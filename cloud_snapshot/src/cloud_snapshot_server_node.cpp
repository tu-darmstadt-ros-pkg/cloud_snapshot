#include "ros/ros.h"

#include <cloud_snapshot/cloud_snapshot_server.h>

int main( int argc, char **argv )
{
  ros::init( argc, argv, "cloud_snapshot_server" );

  ros::NodeHandle nh;

  cloud_snapshot::CloudSnapshotServer cloud_snapshot_server( nh );
  ros::spin();

  return 0;
}
