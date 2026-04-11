#define GET_LIST(list, v) assign_list(list(), v)

template<typename T> void assign_list(const std::vector<T> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  T **data = (T **)malloc(sizeof(void *) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = new T(val[i]);
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}

#define GET_UNIQUE_PTR_LIST(list, v) get_unique_ptr_list(list(), v)

template<typename T> void get_unique_ptr_list(const std::vector<std::unique_ptr<T>> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  T **data = (T **)malloc(sizeof(void *) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = val[i].get();
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}

#define GET_STRS(list, v) assign_strs(list(), v)

static void assign_strs(const std::vector<std::string> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  const char **data = (const char **)malloc(sizeof(void *) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = (new std::string(val[i]))->c_str();
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}

#define GET_INTS(list, v) assign_ints(list(), v)

static void assign_ints(const std::vector<int> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  int *data = (int *)malloc(sizeof(int) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = val[i];
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}

#define GET_ENUMS(list, v) assign_enums(list(), v)

template<typename T> void assign_enums(const std::vector<T> &val, void **target)
{
  GoSlice *slice = (GoSlice *)malloc(sizeof(GoSlice));
  int *data = (int *)malloc(sizeof(int) * val.size());
  for (size_t i = 0; i < val.size(); i++) {
    data[i] = (int)val[i];
  }
  slice->data = (void *)data;
  slice->len = val.size();
  slice->cap = val.size();
  *target = (void *)slice;
}

#define SET_LIST(list, T, v) list(slice_to_vec<T>(v));

template<typename T> std::vector<T> slice_to_vec(void *slice)
{
  GoSlice *goslice = (GoSlice *)slice;
  T **data = (T **)goslice->data;
  std::vector<T> vec;
  for (int i = 0; i < goslice->len; i++) {
    vec.push_back(*data[i]);
  }
  return vec;
}

// Distinct name: root googlesql/bind.cc and public/analyzer/bind.cc both include this header; two
// globals named slice_to_strs would duplicate at link time without -Wl,--allow-multiple-definition.
inline std::vector<std::string> googlesql_public_analyzer_bridge_slice_to_strs(void *slice)
{
  GoSlice *goslice = (GoSlice *)slice;
  char **data = (char **)goslice->data;
  std::vector<std::string> vec;
  for (int i = 0; i < goslice->len; i++) {
    vec.push_back(data[i]);
  }
  return vec;
}

#define UNIQUE_PTR_LIST_TO_VEC(vecptr, T, v) do {                   \
    std::vector<std::unique_ptr<const googlesql::T>> vec;             \
    GoSlice *goslice = (GoSlice *)v;                                \
    googlesql::T **data = (googlesql::T **)goslice->data;               \
    for (int i = 0; i < goslice->len; i++) {                        \
      auto p = googlesql::Make ## T();                                \
      memcpy((void *)p.get(), (void *)data[i], sizeof(googlesql::T)); \
      vec.push_back(std::move(p));                                  \
    }                                                               \
    *vecptr = std::move(vec);                                       \
  } while (0)

#define SET_UNIQUE_PTR(setter, T, v) do {                   \
    auto p = googlesql::Make ## T();                          \
    memcpy((void *)p.get(), (void *)v, sizeof(googlesql::T)); \
    setter(std::move(p));                                   \
  } while (0)

#define SET_INTS(list, v) do {                  \
    std::vector<int> vec;                       \
    GoSlice *goslice = (GoSlice *)v;            \
    int *data = (int *)goslice->data;           \
    for (int i = 0; i < goslice->len; i++) {    \
      vec.push_back(data[i]);                   \
    }                                           \
    list(vec);                                  \
  } while (0)

#define SET_ENUMS(list, T, v) do {              \
    std::vector<T> vec;                         \
    GoSlice *goslice = (GoSlice *)v;            \
    int *data = (int *)goslice->data;           \
    for (int i = 0; i < goslice->len; i++) {    \
      vec.push_back((T)data[i]);                \
    }                                           \
    list(vec);                                  \
  } while (0)

#define SET_UNIQUE_PTR_LIST(list, T, v) do {                        \
    std::vector<std::unique_ptr<const googlesql::T>> vec;             \
    GoSlice *goslice = (GoSlice *)v;                                \
    googlesql::T **data = (googlesql::T **)goslice->data;               \
    for (int i = 0; i < goslice->len; i++) {                        \
      auto p = googlesql::Make ## T();                                \
      memcpy((void *)p.get(), (void *)data[i], sizeof(googlesql::T)); \
      vec.push_back(std::move(p));                                  \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

// ResolvedAggregateScanBase::aggregate_list uses ResolvedComputedColumnBase (subclasses include
// ResolvedComputedColumn and ResolvedDeferredComputedColumn).
#define SET_UNIQUE_PTR_COMPUTED_COLUMN_BASE_LIST(list, v) do {              \
    std::vector<std::unique_ptr<const googlesql::ResolvedComputedColumn>> vec; \
    GoSlice *goslice = (GoSlice *)v;                                          \
    googlesql::ResolvedComputedColumn **data =                                \
        (googlesql::ResolvedComputedColumn **)goslice->data;                  \
    for (int i = 0; i < goslice->len; i++) {                                \
      auto p = googlesql::MakeResolvedComputedColumn();                       \
      memcpy((void *)p.get(), (void *)data[i],                              \
             sizeof(googlesql::ResolvedComputedColumn));                      \
      vec.push_back(std::move(p));                                          \
    }                                                                       \
    std::vector<std::unique_ptr<const googlesql::ResolvedComputedColumnBase>> base_vec; \
    base_vec.reserve(vec.size());                                           \
    for (size_t i = 0; i < vec.size(); i++) {                               \
      base_vec.push_back(std::move(vec[i]));                                \
    }                                                                       \
    list(std::move(base_vec));                                              \
  } while (0)

// ResolvedAggregateScan stores grouping_set_list as unique_ptr<const ResolvedGroupingSetBase>.
#define SET_UNIQUE_PTR_GROUPING_SET_LIST(list, v) do {              \
    std::vector<std::unique_ptr<const googlesql::ResolvedGroupingSet>> vec; \
    GoSlice *goslice = (GoSlice *)v;                                \
    googlesql::ResolvedGroupingSet **data =                           \
        (googlesql::ResolvedGroupingSet **)goslice->data;             \
    for (int i = 0; i < goslice->len; i++) {                        \
      auto p = googlesql::MakeResolvedGroupingSet();                  \
      memcpy((void *)p.get(), (void *)data[i],                      \
             sizeof(googlesql::ResolvedGroupingSet));                 \
      vec.push_back(std::move(p));                                  \
    }                                                               \
    std::vector<std::unique_ptr<const googlesql::ResolvedGroupingSetBase>> base_vec; \
    base_vec.reserve(vec.size());                                   \
    for (size_t i = 0; i < vec.size(); i++) {                       \
      base_vec.push_back(std::move(vec[i]));                        \
    }                                                               \
    list(std::move(base_vec));                                      \
  } while (0)

#define SET_UNIQUE_PTR_EXPR_LIST(list, v) do {                      \
    std::vector<std::unique_ptr<const googlesql::ResolvedExpr>> vec;  \
    GoSlice *goslice = (GoSlice *)v;                                \
    void **data = (void **)goslice->data;                           \
    for (int i = 0; i < goslice->len; i++) {                        \
      vec.push_back(make_unique_expr(data[i]));                     \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

#define SET_UNIQUE_PTR_ACTION_LIST(list, v) do {                    \
    std::vector<std::unique_ptr<const googlesql::ResolvedAlterAction>> vec; \
    GoSlice *goslice = (GoSlice *)v;                                \
    void **data = (void **)goslice->data;                           \
    for (int i = 0; i < goslice->len; i++) {                        \
      vec.push_back(make_unique_action(data[i]));                   \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

#define SET_UNIQUE_PTR_CONSTRAINT_LIST(list, v) do {                    \
    std::vector<std::unique_ptr<const googlesql::ResolvedConstraint>> vec; \
    GoSlice *goslice = (GoSlice *)v;                                    \
    void **data = (void **)goslice->data;                               \
    for (int i = 0; i < goslice->len; i++) {                            \
      vec.push_back(make_unique_constraint(data[i]));                   \
    }                                                                   \
    list(std::move(vec));                                               \
  } while (0)

#define SET_UNIQUE_PTR_SCAN_LIST(list, v) do {                      \
    std::vector<std::unique_ptr<const googlesql::ResolvedExpr>> vec;  \
    GoSlice *goslice = (GoSlice *)v;                                \
    void **data = (void **)goslice->data;                           \
    for (int i = 0; i < goslice->len; i++) {                        \
      vec.push_back(make_unique_scan(data[i]));                     \
    }                                                               \
    list(std::move(vec));                                           \
  } while (0)

#define ADD_UNIQUE_PTR_LIST(list, T, v) do {                \
    auto p = googlesql::Make ## T();                          \
    memcpy((void *)p.get(), (void *)v, sizeof(googlesql::T)); \
    list(std::move(p));                                     \
  } while (0)

#define ADD_UNIQUE_PTR_GROUPING_SET_LIST(list, v) do {      \
    auto p = googlesql::MakeResolvedGroupingSet();            \
    memcpy((void *)p.get(), (void *)v,                      \
           sizeof(googlesql::ResolvedGroupingSet));           \
    list(std::move(p));                                     \
  } while (0)

#define ADD_UNIQUE_PTR_EXPR_LIST(list, v) do {  \
    list(make_unique_expr(v));                  \
  } while (0)

#define ADD_UNIQUE_PTR_ACTION_LIST(list, v) do {    \
    list(make_unique_action(v));                    \
  } while (0)

#define ADD_UNIQUE_PTR_CONSTRAINT_LIST(list, v) do {    \
    list(make_unique_constraint(v));                    \
  } while (0)

#define ADD_UNIQUE_PTR_SCAN_LIST(list, v) do {  \
    list(make_unique_scan(v));                  \
  } while (0)

#define ADD_LIST(list, T, v) list(*(T *)v)
