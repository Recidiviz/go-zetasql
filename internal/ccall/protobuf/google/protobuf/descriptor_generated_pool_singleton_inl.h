// go-zetasql: Inline definitions for the generated EncodedDescriptorDatabase and
// DescriptorPool singletons. When the protobuf amalgamation is compiled into more
// than one CGO archive, anonymous-namespace helpers in descriptor.cc each get a
// distinct database (internal linkage). Marking these as inline merges the static
// locals across TUs (C++ ODR), so registration and lookup use the same pool.

#ifndef GOOGLE_PROTOBUF_DESCRIPTOR_GENERATED_POOL_SINGLETON_INL_H__
#define GOOGLE_PROTOBUF_DESCRIPTOR_GENERATED_POOL_SINGLETON_INL_H__

#include "google/protobuf/descriptor_database.h"

namespace google {
namespace protobuf {

inline EncodedDescriptorDatabase* GeneratedEncodedDescriptorDatabaseSingleton() {
  static EncodedDescriptorDatabase* const db = new EncodedDescriptorDatabase();
  return db;
}

inline DescriptorPool* DescriptorPool::internal_generated_pool() {
  static DescriptorPool* const pool = []() {
    auto* p = new DescriptorPool(GeneratedEncodedDescriptorDatabaseSingleton());
    p->InternalSetLazilyBuildDependencies();
    return p;
  }();
  return pool;
}

inline DescriptorDatabase* DescriptorPool::internal_generated_database() {
  return GeneratedEncodedDescriptorDatabaseSingleton();
}

}  // namespace protobuf
}  // namespace google

#endif  // GOOGLE_PROTOBUF_DESCRIPTOR_GENERATED_POOL_SINGLETON_INL_H__
