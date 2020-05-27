/******************************************************************************
 * Copyright 2020 RoboSense All rights reserved.
 * Suteng Innovation Technology Co., Ltd. www.robosense.ai

 * This software is provided to you directly by RoboSense and might
 * only be used to access RoboSense LiDAR. Any compilation,
 * modification, exploration, reproduction and redistribution are
 * restricted without RoboSense's prior consent.

 * THIS SOFTWARE IS PROVIDED "AS IS" AND ANY EXPRESSED OR IMPLIED
 * WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL ROBOSENSE BE LIABLE FOR ANY DIRECT,
 * INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT,
 * STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
 * IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *****************************************************************************/

#pragma once
#include "common/common_header.h"
#include "lidar_packet_msg.h"
namespace robosense
{
  namespace lidar
  {
/**
   * @brief Lidar Scan Message for Robosense SDK.
   * @detail Robosense LidarScanMsg is defined for passing lidar packets scan accross different modules
   *         If ROS is turned on , we provide translation functions between ROS message and Robosense message
   *         If Proto is turned on , we provide translation functions between Protobuf message and Robosense message
   */
#ifdef _MSC_VER
#pragma pack(push, 2)
    struct LidarScanMsg
#elif __GNUC__
    struct alignas(16) LidarScanMsg
#endif
    {
      double timestamp = 0.0;
      uint32_t seq = 0;
      std::string parent_frame_id = "";
      std::string frame_id = "";

      std::vector<LidarPacketMsg> packets; ///< a vector which store a scan of packets (the size of the vector is not fix)
    };
#ifdef _MSC_VER
#pragma pack(pop)
#endif
  } // namespace lidar
} // namespace robosense
