#ifndef NDNFD_NS3_UTILS_LOGGING_H_
#define NDNFD_NS3_UTILS_LOGGING_H_
#include "util/logging.h"
namespace ndnfd {

// SimLogging prepends nodeid and time to each log line.
class SimLogging : public Logging {
 public:
  SimLogging(uint32_t nodeid) : nodeid_(nodeid) {}
  virtual std::string line_prefix(void);

 private:
  uint32_t nodeid_;
};

};//namespace ndnfd
#endif//NDNFD_NS3_UTILS_LOGGING_H_
