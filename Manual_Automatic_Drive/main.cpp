#include "Aria.h"

int main(int argc, char **argv)
{
  Aria::init(); // Initialize some global data
  ArArgumentParser parser(&argc, argv); // This object parses program options from the command line
  parser.loadDefaultArguments(); //Load some default values
  ArRobot robot; // Central object
  ArRobotConnector robotConnector(&parser, &robot); // Object that connects to the robot
  
  if (!robotConnector.connectRobot())
  {
    // Error connecting
    if (!parser.checkHelpAndWarnUnparsed())
    {
      ArLog::log(ArLog::Terse, "-->Could not connect to robot, will not have parameter file so options displayed later may not include everything");
    }
    // otherwise abort
    else
    {
      ArLog::log(ArLog::Terse, "-->Error, could not connect to robot.");
      Aria::logOptions();
      Aria::exit(1);
    }
  }

  // Parse the command line options
  if (!Aria::parseArgs() || !parser.checkHelpAndWarnUnparsed())
  {    
    Aria::logOptions();
    exit(1);
  }

  // Used to perform actions when keyboard keys are pressed
  ArKeyHandler keyHandler;
  Aria::setKeyHandler(&keyHandler);

  // Keydrive action
  ArActionKeydrive keydriveAct;
  keydriveAct.setSpeeds (200, 10);

  robot.attachKeyHandler(&keyHandler);
  robot.addAction(&keydriveAct, 100);

  robot.runAsync(true);
  printf("-->Drive with Keyboard.\n");
  robot.enableMotors();
  
  int iteration = 1;

  while (1) 
  {
    keydriveAct.activate();
    ArUtil::sleep(100);

    if(keyHandler.getKey()==97) //a
    {
      printf("-->Drive Automatic.\n");
      keydriveAct.deactivate();
      ArUtil::sleep(100);

      while (iteration<2) 
      {
        //ArLog::log(ArLog::Normal, "-->Driving forward.");
        robot.lock();
        robot.setVel(100);
        robot.unlock();
        ArUtil::sleep(40000);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        //ArLog::log(ArLog::Normal, "-->Rotating.");
        robot.lock();
        robot.setRotVel(10);
        robot.unlock();
        ArUtil::sleep(8300);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        //ArLog::log(ArLog::Normal, "-->Driving forward.");
        robot.lock();
        robot.setVel(100);
        robot.unlock();
        ArUtil::sleep(5000);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        //ArLog::log(ArLog::Normal, "-->Rotating.");
        robot.lock();
        robot.setRotVel(10);
        robot.unlock();
        ArUtil::sleep(8000);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        //ArLog::log(ArLog::Normal, "-->Driving forward.");
        robot.lock();
        robot.setVel(100);
        robot.unlock();
        ArUtil::sleep(40000);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        //ArLog::log(ArLog::Normal, "-->Rotating.");
        robot.lock();
        robot.setRotVel(10);
        robot.unlock();
        ArUtil::sleep(8650);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        //ArLog::log(ArLog::Normal, "-->Driving forward.");
        robot.lock();
        robot.setVel(100);
        robot.unlock();
        ArUtil::sleep(5000);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        //ArLog::log(ArLog::Normal, "-->Rotating.");
        robot.lock();
        robot.setRotVel(10);
        robot.unlock();
        ArUtil::sleep(8000);

        //ArLog::log(ArLog::Normal, "-->Stopping.");
        robot.lock();
        robot.stop();
        robot.unlock();
        ArUtil::sleep(1000);

        iteration++;
      }
      printf("-->Drive with Keyboard.\n");
      iteration=1;
      robot.clearDirectMotion();
    }
  }

  // Robot disconnected or time elapsed, shut down
  printf("-->Shutting down ARIA and exiting.\n");
  Aria::shutdown();
  return 0;
}