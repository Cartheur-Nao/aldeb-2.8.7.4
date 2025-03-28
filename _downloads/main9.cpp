#include <qi/applicationsession.hpp>
#include <boost/shared_ptr.hpp>
#include "imageservice.h"

int main(int argc, char* argv[])
{
  qi::ApplicationSession app(argc, argv);
  app.startSession();
  qi::SessionPtr session = app.session();
  session->registerService("ImageService", qi::AnyObject(boost::make_shared<ImageService>(session)));
  app.run();
  return 0;
}

