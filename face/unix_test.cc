#include "unix.h"
#include "message/ccnb.h"
#include "core/element_testh.h"
#include "gtest/gtest.h"
namespace ndnfd {

TEST(FaceTest, Unix) {
  Ptr<CcnbWireProtocol> ccnbwp = new CcnbWireProtocol(true);
  
  TestGlobal->set_pollmgr(NewTestElement<PollMgr>());
  TestGlobal->set_facemgr(NewTestElement<FaceMgr>());

  Ptr<UnixFaceFactory> factory = NewTestElement<UnixFaceFactory>(ccnbwp);
  Ptr<StreamListener> listener = factory->Listen("UnixFaceTest.sock");
  EXPECT_TRUE(listener->CanAccept());
  listener->Close();
}


};//namespace ndnfd
