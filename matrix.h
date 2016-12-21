#ifndef __MATRIX_H__
#define __MATRIX_H__

#ifdef __cplusplus
extern "C" {
#endif

  void* matrix_new(size_t, size_t);
  double matrix_get(void*, size_t, size_t);
  void matrix_set(void*, size_t, size_t, double);
  void matrix_free(void*);

#ifdef __cplusplus
}
#endif

#endif  // __MATRIX_H__
