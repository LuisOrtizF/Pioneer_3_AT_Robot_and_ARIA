#include "Aria.h"

class CallbackContainer
{
public:
  void callback2(int i);
};

void CallbackContainer::callback2(int i)
{
  ArLog::log(ArLog::Normal, "-->%d", i);
}

int main(int argc, char** argv)
{
  Aria::init();
  ArArgumentParser parser(&argc, argv);
  parser.loadDefaultArguments();
  ArRobot robot;
  ArRobotConnector robotConnector(&parser, &robot);

  if (!robotConnector.connectRobot())
  {
    if (!parser.checkHelpAndWarnUnparsed())
    {
      ArLog::log(ArLog::Terse, "-->Could not connect to robot, will not have parameter file so options displayed later may not include everything.");
    }
    else
    {
      ArLog::log(ArLog::Terse, "-->Error, could not connect to the robot!");
      Aria::logOptions();
      Aria::exit(1);
    }
  }

  if(!robot.isConnected())
  {
    ArLog::log(ArLog::Terse, "-->Robot connector succeeded but ArRobot::isConnected() is false!");
  }

  if (!Aria::parseArgs() || !parser.checkHelpAndWarnUnparsed())
  {    
    Aria::logOptions();
    Aria::exit(1);
    return 1;
  }

  robot.runAsync(true);
  ArUtil::sleep(1000);
  
  ArKeyHandler *keyHandler = Aria::getKeyHandler();
  if (keyHandler == NULL)
  {
    keyHandler = new ArKeyHandler;
    Aria::setKeyHandler(keyHandler);
    robot.attachKeyHandler(keyHandler);
  }

  CallbackContainer cb;
  ArFunctor1C<CallbackContainer, int> functor2(cb, &CallbackContainer::callback2, 101);
  keyHandler->addKeyHandler('m', &functor2);

  robot.waitForRunExit();

  Aria::exit(0);
  return 0;
}
