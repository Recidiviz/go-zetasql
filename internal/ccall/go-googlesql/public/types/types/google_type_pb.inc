#ifndef GOOGLESQL_PUBLIC_TYPES_TYPES_GOOGLE_TYPE_PB_INC
#define GOOGLESQL_PUBLIC_TYPES_TYPES_GOOGLE_TYPE_PB_INC

#ifndef GOOGLESQL_GOOGLE_TYPE_DATE_SYM_PREFIX
#error "define GOOGLESQL_GOOGLE_TYPE_DATE_SYM_PREFIX before including google_type_pb.inc"
#endif
#ifndef GOOGLESQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX
#error "define GOOGLESQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX before including google_type_pb.inc"
#endif

#define GOOGLESQL_GOOGLE_TYPE_CAT2_(a, b) a##b
#define GOOGLESQL_GOOGLE_TYPE_CAT2(a, b) GOOGLESQL_GOOGLE_TYPE_CAT2_(a, b)

#include "googleapis/google/type/date.pb.h"
#define schemas GOOGLESQL_GOOGLE_TYPE_CAT2(GOOGLESQL_GOOGLE_TYPE_DATE_SYM_PREFIX, _schemas)
#define file_default_instances \
  GOOGLESQL_GOOGLE_TYPE_CAT2(GOOGLESQL_GOOGLE_TYPE_DATE_SYM_PREFIX, _file_default_instances)
#include "googleapis/google/type/date.pb.cc"
#undef file_default_instances
#undef schemas

#include "googleapis/google/type/timeofday.pb.h"
#define schemas GOOGLESQL_GOOGLE_TYPE_CAT2(GOOGLESQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX, _schemas)
#define file_default_instances \
  GOOGLESQL_GOOGLE_TYPE_CAT2(GOOGLESQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX, _file_default_instances)
#include "googleapis/google/type/timeofday.pb.cc"
#undef file_default_instances
#undef schemas

#undef GOOGLESQL_GOOGLE_TYPE_CAT2
#undef GOOGLESQL_GOOGLE_TYPE_CAT2_

#endif /* GOOGLESQL_PUBLIC_TYPES_TYPES_GOOGLE_TYPE_PB_INC */
