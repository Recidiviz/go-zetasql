// Protocol Buffers - Google's data interchange format
// Out-of-line definitions for google/protobuf/stubs/logging.h (CGO amalgamation).

#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <string>

#include "google/protobuf/stubs/int128.h"
#include "google/protobuf/stubs/logging.h"
#include "google/protobuf/stubs/status.h"
#include "google/protobuf/stubs/stringpiece.h"

namespace google {
namespace protobuf {

namespace {

LogHandler* log_handler = nullptr;
std::atomic<int> log_silencer_count{0};

}  // namespace

LogHandler* SetLogHandler(LogHandler* new_func) {
  LogHandler* old = log_handler;
  log_handler = new_func;
  return old;
}

LogSilencer::LogSilencer() { ++log_silencer_count; }

LogSilencer::~LogSilencer() { --log_silencer_count; }

namespace internal {

LogMessage::LogMessage(LogLevel level, const char* filename, int line)
    : level_(level), filename_(filename), line_(line) {}

LogMessage::~LogMessage() { Finish(); }

void LogMessage::Finish() {
  if (log_silencer_count.load(std::memory_order_relaxed) > 0 &&
      level_ != LOGLEVEL_FATAL) {
    return;
  }
  if (log_handler != nullptr) {
    log_handler(level_, filename_, line_, message_);
  } else {
    fprintf(stderr, "[%s:%d] %s\n", filename_ ? filename_ : "?", line_,
            message_.c_str());
  }
  if (level_ == LOGLEVEL_FATAL) {
    abort();
  }
}

LogMessage& LogMessage::operator<<(const std::string& value) {
  message_ += value;
  return *this;
}

LogMessage& LogMessage::operator<<(const char* value) {
  if (value != nullptr) {
    message_ += value;
  }
  return *this;
}

LogMessage& LogMessage::operator<<(char value) {
  message_.push_back(value);
  return *this;
}

LogMessage& LogMessage::operator<<(int value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(unsigned int value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(long value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(unsigned long value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(long long value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(unsigned long long value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(double value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(void* value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

LogMessage& LogMessage::operator<<(const StringPiece& value) {
  message_.append(value.data(), static_cast<size_t>(value.size()));
  return *this;
}

LogMessage& LogMessage::operator<<(const util::Status& status) {
  message_ += status.ToString();
  return *this;
}

LogMessage& LogMessage::operator<<(const uint128& value) {
  std::ostringstream s;
  s << value;
  message_ += s.str();
  return *this;
}

void LogFinisher::operator=(LogMessage& other) {
  (void)other;
}

}  // namespace internal
}  // namespace protobuf
}  // namespace google
