/*
 * Copyright (C) 2009-2017 National Technology & Engineering Solutions of
 * Sandia, LLC (NTESS).  Under the terms of Contract DE-NA0003525 with
 * NTESS, the U.S. Government retains certain rights in this software.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are
 * met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *
 *     * Redistributions in binary form must reproduce the above
 *       copyright notice, this list of conditions and the following
 *       disclaimer in the documentation and/or other materials provided
 *       with the distribution.
 *
 *     * Neither the name of NTESS nor the names of its
 *       contributors may be used to endorse or promote products derived
 *       from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 * A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 * OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 * LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 */

#ifndef _ELB_UTIL_CONST_H_
#define _ELB_UTIL_CONST_H_

#include <cstddef>     // for size_t
#include <sys/types.h> // for ssize_t
#include <vector>

#if defined(_MSC_VER)
#define strcasecmp stricmp
#define strncasecmp strnicmp
#ifdef _WIN64
#define ssize_t __int64
#else
#define ssize_t long
#endif
#endif

/* Function prototypes */
extern int token_compare(char *      token, /* The input character string */
                         const char *key    /* The key to compare with token */
);

extern void strip_string(char        inp_str[], /* The string to strip */
                         const char *tokens     /* The tokens to strip from the beginning and
                                                 * end of the input string */
);

extern void clean_string(char        inp_str[], /* The string to clean */
                         const char *tokens     /* The tokens to strip multiple copies of */
);

extern void string_to_lower(char in_string[], /* The string to convert to lower case */
                            char cval         /* Character where to stop */
);

template <typename INT> void gds_qsort(INT v[], size_t N);

template <typename INT> void qsort4(INT *v1, INT *v2, INT *v3, INT *v4, size_t N);

template <typename INT> void qsort2(INT *v1, INT *v2, size_t N);

template <typename INT> inline void SWAP(INT &r, INT &s)
{
  INT t = r;
  r     = s;
  s     = t;
}

template <typename INT> void siftDown(INT *a, INT *b, size_t start, size_t end)
{
  size_t root = start;

  while (root * 2 + 1 < end) {
    size_t child = 2 * root + 1;
    if ((child + 1 < end) && (a[child] < a[child + 1])) {
      child += 1;
    }
    if (a[root] < a[child]) {
      SWAP(a[child], a[root]);
      SWAP(b[child], b[root]);
      root = child;
    }
    else {
      return;
    }
  }
}

template <typename INT> void sort2(ssize_t count, INT ra[], INT rb[])
{
  if (count <= 1) {
    return;
  }
  /* heapify */
  for (ssize_t start = (count - 2) / 2; start >= 0; start--) {
    siftDown(ra, rb, start, count);
  }

  for (size_t end = count - 1; end > 0; end--) {
    SWAP(ra[end], ra[0]);
    SWAP(rb[end], rb[0]);
    siftDown(ra, rb, 0, end);
  }
}

template <typename INT> void sort3(ssize_t count, INT ra[], INT rb[], INT rc[]);

template <typename INT>
void find_first_last(INT val, size_t vecsize, INT *vector, INT *first, INT *last);

template <typename INT>
ssize_t find_int(INT value1, INT value2, size_t start, size_t stop, INT *vector1, INT *vector2);

template <typename INT> ssize_t in_list(INT value, size_t count, INT *vector);

template <typename INT> ssize_t in_list(INT value, std::vector<INT> vector);

extern int roundfloat(float value /* the value to be rounded */
);

template <typename INT>
size_t find_inter(const INT set1[],     /* the first set of integers */
                  const INT set2[],     /* the second set of integers */
                  size_t    length1,    /* the length of the first set */
                  size_t    length2,    /* the length of the second set */
                  INT       inter_ptr[] /* the values in the intersection */
);

template <typename INT> ssize_t bin_search2(INT value, size_t num, INT List[]);

#endif /* _ELB_UTIL_CONST_H_ */
