# ros start

## Ubuntu svn
安裝
```
sudo apt-get install subversion
```
下載
```
svn checkout https://140.118.206.177/svn/ivam_svn/
```

## 安裝包
```
sudo apt-get install ros-melodic-pr2-navigation
```

## 創建
新增資料夾
```
mkdir -p ~/catkin_ws/src
cd ~/catkin_ws/
catkin_make
```


環境變數
```
source devel/setup.bash
```

## 烏龜

catkin_create_pkg
```
catkin_create_pkg beginner_tutorials std_msgs rospy roscpp
```

開啟烏龜
```
rosrun turtlesim turtlesim_node
```
開啟烏龜rename
```
rosrun turtlesim turtlesim_node __name:=turtlesim2
```
控龜
```
rosrun turtlesim turtle_teleop_key
```

看龜點
```
rostopic echo / turtle1 / cmd_vel
```

跑一段
```
rostopic pub -1 /turtle1/cmd_vel geometry_msgs/Twist -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
```
馬拉松
```
rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, 1.8]'
```

## 檢視
節點圖
```
rosrun rqt_graph rqt_graph
```
差看圖表
```
rosrun rqt_plot rqt_plot
```

## Service


```
rosservice list
```

```
rosservice type /clear
```

```
rosservice call clear
```
```
rosservice call /spawn 2 2 0.2 ""
```
```
rosparam list
```
```
rosparam set background_r 150
```
```
rosservice call /clear
```
```
rosparam get /
```

## launch

新增 launch
```
mkdir ~/catkin_ws/src/beginner_tutorials/launch
```

新增 launch
```
touch turtlemimic.launch
```

新增 launch
```
<?xml version="1.0"?>
<launch>

<group ns="turtlesim1">
<node pkg="turtlesim" name="sim" type="turtlesim_node"/>
</group>

<group ns="turtlesim2">
<node pkg="turtlesim" name="sim" type="turtlesim_node"/>
</group>

<node pkg="turtlesim" name="mimic" type="mimic">
<remap from="input" to="turtlesim1/turtle1"/>
<remap from="output" to="turtlesim2/turtle1"/>
</node>

</launch>
```virtual keyboard joystick

```
rostopic pub /turtlesim1/turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'
```

```
rqt_graph
```

## launch msg
```

cd catkin_ws_20200714/

source devel/setup.bash

catkin_make

rosmsg show beginner_tutorials/Num
```

## talker and listener
```

roscore

rosrun beginner_tutorials talker

rosrun beginner_tutorials listener

## launch srv

```
roscp rospy_tutorials AddTwoInts.srv srv/AddTwoInts.srv

rosrun beginner_tutorials talker
```

## package joystick

```
sudo apt-get install libusb-dev

sudo apt-get install libbluetooth-dev

sudo apt-get install libspnav-dev

sudo apt-get install libcwiid-dev

ls /dev/input/
```
## turtlebot

安裝ros
```
sudo apt-get update
sudo apt-get upgrade
wget https://raw.githubusercontent.com/ROBOTIS-GIT/robotis_tools/master/install_ros_melodic.sh && chmod 755 ./install_ros_melodic.sh && bash ./install_ros_melodic.sh
```

install TurtleBot3 packages
```
sudo apt-get install ros-melodic-joy ros-melodic-teleop-twist-joy ros-melodic-teleop-twist-keyboard ros-melodic-laser-proc ros-melodic-rgbd-launch ros-melodic-depthimage-to-laserscan ros-melodic-rosserial-arduino ros-melodic-rosserial-python ros-melodic-rosserial-server ros-melodic-rosserial-client ros-melodic-rosserial-msgs ros-melodic-amcl ros-melodic-map-server ros-melodic-move-base ros-melodic-urdf ros-melodic-xacro ros-melodic-compressed-image-transport ros-melodic-rqt-image-view ros-melodic-gmapping ros-melodic-navigation ros-melodic-interactive-markers
```

src
```
git clone https://github.com/ROBOTIS-GIT/turtlebot3_msgs.git
git clone -b kinetic-devel https://github.com/ROBOTIS-GIT/turtlebot3.git
git clone https://github.com/ROBOTIS-GIT/turtlebot3_simulations.git
```

run
```
source devel/setup.bash

export TURTLEBOT3_MODEL=burger

roslaunch turtlebot3_gazebo turtlebot3_world.launch
roslaunch turtlebot3_gazebo turtlebot3_house.launch

roslaunch turtlebot3_slam turtlebot3_slam.launch slam_methods:=gmapping

roslaunch turtlebot3_navigation turtlebot3_navigation.launch map_file:=$HOME/map.yaml
```

## hokuyo

https://blog.csdn.net/Spacegene/article/details/84844741
```

sudo apt-get install ros-melodic-driver-base

mkdir -p ~/ws_moveit/src
cd ~/ws_moveit/src

ls -l /dev/ttyACM0

sudo chmod a+rw /dev/ttyACM0

rosrun hokuyo_node hokuyo_node

rostopic echo /scan

rosrun rviz rviz

rosrun gmapping slam_gmapping

rosrun map_server map_server map.yaml
```
## tf
```
roslaunch learning_tf start_demo.launch

rostopic pub /turtle1/cmd_vel geometry_msgs/Twist -r 1 -- '[2.0, 0.0, 0.0]' '[0.0, 0.0, -1.8]'
```

## compile

    cd catkin_ws/
    catkin_make -DCMAKE_EXPORT_COMPILE_COMMANDS=1
    cp build/compile_commands.json src/

    restart vscode, or manually add ${workspaceFolder}/compile_commands.json to Configuration UI, advanced settings, compile commands

### ros2
    colcon build --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
    alias colcon_build="colcon build"
    alias colcon_build_json="colcon build --cmake-args -DCMAKE_EXPORT_COMPILE_COMMANDS=ON"






