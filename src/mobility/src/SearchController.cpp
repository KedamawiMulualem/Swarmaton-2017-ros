#include "SearchController.h"

int SearchController::counter = 1;
int SearchController::sign = 1;

SearchController::SearchController() {

}

/**
 * This code implements a basic random walk search.
 */
geometry_msgs::Pose2D SearchController::search(geometry_msgs::Pose2D currentLocation) {
  geometry_msgs::Pose2D goalLocation;
int xx=0;
int yy=0;



  if (counter%2==0)
	{xx=counter;}
else {
	yy=counter;}

  //select new heading from Gaussian distribution around current heading
 

  //select new position 50 cm from current location

  goalLocation.x = currentLocation.x + xx;
  goalLocation.y = currentLocation.y + yy;
if (counter%2==0)
	{sign=sign*-1;}
counter++;
  return goalLocation;
}

/**
 * Continues search pattern after interruption. For example, avoiding the
 * center or collisions.
 */
geometry_msgs::Pose2D SearchController::continueInterruptedSearch(geometry_msgs::Pose2D currentLocation, geometry_msgs::Pose2D oldGoalLocation) {
  geometry_msgs::Pose2D newGoalLocation;

  //remainingGoalDist avoids magic numbers by calculating the dist
  double remainingGoalDist = hypot(oldGoalLocation.x - currentLocation.x, oldGoalLocation.y - currentLocation.y);

  //this of course assumes random walk continuation. Change for diffrent search methods.
  newGoalLocation.theta = oldGoalLocation.theta;
  newGoalLocation.x = currentLocation.x + (0.50 * cos(oldGoalLocation.theta)); //(remainingGoalDist * cos(oldGoalLocation.theta));
  newGoalLocation.y = currentLocation.y + (0.50 * sin(oldGoalLocation.theta)); //(remainingGoalDist * sin(oldGoalLocation.theta));

  return newGoalLocation;
}
