// Go bind calls this symbol (not GO_EXPORT(FormatSql)) so root //export linkname stubs can
// forward to sql_formatter_FormatSql without cgo resolving C.export_* back to the same Go export.
void googlesql_format_sql_go_shim(void * arg0, void ** arg1, void ** arg2)
{
  std::string out;
  absl::Status ret = googlesql::FormatSql((char *)arg0, &out);
  *arg1 = (void *)((new std::string(out))->c_str());
  *arg2 = (void *)(new absl::Status(ret));
}

void GO_EXPORT(FormatSql)(void * arg0,void ** arg1,void ** arg2)
{
  googlesql_format_sql_go_shim(arg0, arg1, arg2);
}
