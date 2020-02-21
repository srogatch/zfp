#ifndef CFP_ARRAY_2F
#define CFP_ARRAY_2F

#include <stddef.h>
#include "zfp/types.h"

typedef struct {
  void* object;
} cfp_array2f;

typedef struct {
  uint i;
  uint j;
  cfp_array2f array;
} cfp_ref2f;

typedef struct {
  cfp_ref2f reference;
} cfp_ptr2f;

typedef struct {
  uint i;
  uint j;
  cfp_array2f array;
} cfp_iter2f;

typedef struct {
  float (*get)(cfp_ref2f self);
  void (*set)(cfp_ref2f self, float val);
  void (*copy)(cfp_ref2f self, cfp_ref2f src);
  cfp_ptr2f (*ptr)(cfp_ref2f self);
} cfp_ref2f_api;

typedef struct {
  cfp_ref2f (*ref)(cfp_ptr2f self);
  cfp_ref2f (*offset_ref)(cfp_ptr2f self, int i);
  int (*eq)(cfp_ptr2f self, cfp_ptr2f src);
  int (*diff)(cfp_ptr2f self, cfp_ptr2f src);
  cfp_ptr2f (*shift)(cfp_ptr2f self, int i);
  cfp_ptr2f (*inc)(cfp_ptr2f self);
  cfp_ptr2f (*dec)(cfp_ptr2f self);
} cfp_ptr2f_api;

typedef struct {
  cfp_ref2f (*ref)(cfp_iter2f self);
  cfp_iter2f (*inc)(cfp_iter2f self);
  int (*eq)(cfp_iter2f self, cfp_iter2f src);
  uint (*i)(cfp_iter2f self);
  uint (*j)(cfp_iter2f self);
} cfp_iter2f_api;

typedef struct {
  cfp_array2f (*ctor_default)();
  cfp_array2f (*ctor)(uint nx, uint ny, double rate, const float* p, size_t csize);
  cfp_array2f (*ctor_copy)(const cfp_array2f src);
  void (*dtor)(cfp_array2f self);

  void (*deep_copy)(cfp_array2f self, const cfp_array2f src);

  double (*rate)(const cfp_array2f self);
  double (*set_rate)(cfp_array2f self, double rate);
  size_t (*cache_size)(const cfp_array2f self);
  void (*set_cache_size)(cfp_array2f self, size_t csize);
  void (*clear_cache)(const cfp_array2f self);
  void (*flush_cache)(const cfp_array2f self);
  size_t (*compressed_size)(const cfp_array2f self);
  uchar* (*compressed_data)(const cfp_array2f self);
  size_t (*size)(const cfp_array2f self);
  uint (*size_x)(const cfp_array2f self);
  uint (*size_y)(const cfp_array2f self);
  void (*resize)(cfp_array2f self, uint nx, uint ny, int clear);

  void (*get_array)(const cfp_array2f self, float* p);
  void (*set_array)(cfp_array2f self, const float* p);
  float (*get_flat)(const cfp_array2f self, uint i);
  void (*set_flat)(cfp_array2f self, uint i, float val);
  float (*get)(const cfp_array2f self, uint i, uint j);
  void (*set)(cfp_array2f self, uint i, uint j, float val);

  cfp_ref2f (*ref)(cfp_array2f self, uint i, uint j);
  cfp_ref2f (*flat_ref)(cfp_array2f self, uint i);

  cfp_ptr2f (*ptr)(cfp_array2f self, uint i, uint j);
  cfp_ptr2f (*flat_ptr)(cfp_array2f self, uint i);

  cfp_iter2f (*begin)(cfp_array2f self);
  cfp_iter2f (*end)(cfp_array2f self);

  cfp_ref2f_api reference;
  cfp_ptr2f_api pointer;
  cfp_iter2f_api iterator;
} cfp_array2f_api;

#endif
