#include "cloud_snapshot/cloud_snapshot_server.h"

#include <sensor_msgs/PointCloud2.h>

namespace cloud_snapshot
{
CloudSnapshotServer::CloudSnapshotServer( ros::NodeHandle &nh )
{
  server_ = nh.advertiseService( "cloud_snapshot", &CloudSnapshotServer::pointCloudCallback, this );

  point_cloud_pub_ = nh.advertise<sensor_msgs::PointCloud2>( "/cloud_snapshot", 1, true );
}

bool CloudSnapshotServer::pointCloudCallback( cloud_snapshot_msgs::CloudSnapshot::Request &req,
                                              cloud_snapshot_msgs::CloudSnapshot::Response &res )
{
  auto point_cloud_msg = ros::topic::waitForMessage<sensor_msgs::PointCloud2>(
      req.input_topic, ros::Duration( 3.0 ) );
  if ( point_cloud_msg == nullptr ) {
    res.result = cloud_snapshot_msgs::CloudSnapshot::Response::FAILURE;
    res.error_msg = "Failed to receive point cloud message";
    return true;
  }
  point_cloud_pub_.publish( point_cloud_msg );
  res.result = cloud_snapshot_msgs::CloudSnapshot::Response::SUCCESS;
  return true;
}
} // namespace cloud_snapshot
