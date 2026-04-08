// go-zetasql: Singleton definitions for DescriptorPool::generated_pool() and
// EncodedDescriptorDatabase backing the generated descriptor pool. Included
// once from go-protobuf/protobuf/export.inc immediately after descriptor.cc so
// static data is not duplicated when descriptor.cc is linked into multiple
// objects with --allow-multiple-definition.
//
// This file is included after descriptor.cc closes its namespace blocks, so it
// opens google::protobuf explicitly (matches the code that lived in
// descriptor.cc).

namespace google {
namespace protobuf {

// generated_pool ====================================================

namespace {


EncodedDescriptorDatabase* GeneratedDatabase() {
  static auto generated_database =
      internal::OnShutdownDelete(new EncodedDescriptorDatabase());
  return generated_database;
}

DescriptorPool* NewGeneratedPool() {
  auto generated_pool = new DescriptorPool(GeneratedDatabase());
  generated_pool->InternalSetLazilyBuildDependencies();
  return generated_pool;
}

}  // anonymous namespace

DescriptorDatabase* DescriptorPool::internal_generated_database() {
  return GeneratedDatabase();
}

DescriptorPool* DescriptorPool::internal_generated_pool() {
  static DescriptorPool* generated_pool =
      internal::OnShutdownDelete(NewGeneratedPool());
  return generated_pool;
}

const DescriptorPool* DescriptorPool::generated_pool() {
  const DescriptorPool* pool = internal_generated_pool();
  // Ensure that descriptor.proto gets registered in the generated pool. It is a
  // special case because it is included in the full runtime. We have to avoid
  // registering it pre-main, because we need to ensure that the linker
  // --gc-sections step can strip out the full runtime if it is unused.
  DescriptorProto::descriptor();
  return pool;
}

}  // namespace protobuf
}  // namespace google
