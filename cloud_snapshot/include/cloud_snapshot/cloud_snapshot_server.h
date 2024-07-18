#ifndef CLOUD_SNAPSHOT_SERVER_H_
#define CLOUD_SNAPSHOT_SERVER_H_

#include <ros/ros.h>
#include <cloud_snapshot_msgs/CloudSnapshot.h>

namespace cloud_snapshot
{
    class CloudSnapshotServer
    {
    public:
        CloudSnapshotServer(ros::NodeHandle& nh);

    protected:
        bool pointCloudCallback(cloud_snapshot_msgs::CloudSnapshot::Request& req,
                                cloud_snapshot_msgs::CloudSnapshot::Response& res);

        ros::Subscriber point_cloud_sub_;

        ros::Publisher point_cloud_pub_;

        ros::ServiceServer server_;
    };
} // namespace cloud_snapshot

#endif //CLOUD_SNAPSHOT_SERVER_H_
