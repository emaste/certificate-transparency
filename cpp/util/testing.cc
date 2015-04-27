#include "util/testing.h"

#include <event2/thread.h>
#include <glog/logging.h>
#include <gtest/gtest.h>

#include "config.h"

DEFINE_string(test_srcdir, TEST_SRCDIR, "top-level of the source tree");

namespace cert_trans {
namespace test {

void InitTesting(const char* name, int* argc, char*** argv,
                 bool remove_flags) {
  ::testing::InitGoogleTest(argc, *argv);
  gflags::ParseCommandLineFlags(argc, argv, remove_flags);
  google::InitGoogleLogging(name);
  google::InstallFailureSignalHandler();
  evthread_use_pthreads();
}

}  // namespace test
}  // namespace cert_trans
