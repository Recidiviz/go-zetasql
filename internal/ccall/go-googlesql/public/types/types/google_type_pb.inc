#ifndef ZETASQL_PUBLIC_TYPES_TYPES_GOOGLE_TYPE_PB_INC
#define ZETASQL_PUBLIC_TYPES_TYPES_GOOGLE_TYPE_PB_INC

#ifndef ZETASQL_GOOGLE_TYPE_DATE_SYM_PREFIX
#error "define ZETASQL_GOOGLE_TYPE_DATE_SYM_PREFIX before including google_type_pb.inc"
#endif
#ifndef ZETASQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX
#error "define ZETASQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX before including google_type_pb.inc"
#endif

#define ZETASQL_GOOGLE_TYPE_CAT2_(a, b) a##b
#define ZETASQL_GOOGLE_TYPE_CAT2(a, b) ZETASQL_GOOGLE_TYPE_CAT2_(a, b)

#include "googleapis/google/type/date.pb.h"
#define schemas ZETASQL_GOOGLE_TYPE_CAT2(ZETASQL_GOOGLE_TYPE_DATE_SYM_PREFIX, _schemas)
#define file_default_instances \
  ZETASQL_GOOGLE_TYPE_CAT2(ZETASQL_GOOGLE_TYPE_DATE_SYM_PREFIX, _file_default_instances)
#include "googleapis/google/type/date.pb.cc"
#undef file_default_instances
#undef schemas

#include "googleapis/google/type/timeofday.pb.h"
#define schemas ZETASQL_GOOGLE_TYPE_CAT2(ZETASQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX, _schemas)
#define file_default_instances \
  ZETASQL_GOOGLE_TYPE_CAT2(ZETASQL_GOOGLE_TYPE_TIMEOFDAY_SYM_PREFIX, _file_default_instances)
#include "googleapis/google/type/timeofday.pb.cc"
#undef file_default_instances
#undef schemas

#undef ZETASQL_GOOGLE_TYPE_CAT2
#undef ZETASQL_GOOGLE_TYPE_CAT2_

#endif /* ZETASQL_PUBLIC_TYPES_TYPES_GOOGLE_TYPE_PB_INC */
