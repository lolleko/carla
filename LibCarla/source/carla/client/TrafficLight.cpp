// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#include "carla/client/TrafficLight.h"

#include "carla/client/detail/Simulator.h"

namespace carla {
namespace client {

  void TrafficLight::SetState(rpc::TrafficLightState state) {
    GetEpisode().Lock()->SetTrafficLightState(*this, state);
  }

  rpc::TrafficLightState TrafficLight::GetState() const {
    return GetEpisode().Lock()->GetActorDynamicState(*this).state.traffic_light_data.state;
  }

  void TrafficLight::SetGreenTime(float green_time) {
    GetEpisode().Lock()->SetTrafficLightGreenTime(*this, green_time);
  }

  float TrafficLight::GetGreenTime() const {
    return GetEpisode().Lock()->GetActorDynamicState(*this).state.traffic_light_data.green_time;
  }

  void TrafficLight::SetYellowTime(float yellow_time) {
    GetEpisode().Lock()->SetTrafficLightYellowTime(*this, yellow_time);
  }

  float TrafficLight::GetYellowTime() const {
    return GetEpisode().Lock()->GetActorDynamicState(*this).state.traffic_light_data.yellow_time;
  }

  void TrafficLight::SetRedTime(float red_time) {
    GetEpisode().Lock()->SetTrafficLightRedTime(*this, red_time);
  }

  float TrafficLight::GetRedTime() const {
    return GetEpisode().Lock()->GetActorDynamicState(*this).state.traffic_light_data.red_time;
  }

  float TrafficLight::GetElapsedTime() const {
    return GetEpisode().Lock()->GetActorDynamicState(*this).state.traffic_light_data.elapsed_time;
  }

  void TrafficLight::Freeze(bool freeze) {
    GetEpisode().Lock()->FreezeTrafficLight(*this, freeze);
  }

  bool TrafficLight::IsFrozen() const {
    return GetEpisode().Lock()->GetActorDynamicState(*this).state.traffic_light_data.time_is_frozen;
  }

} // namespace client
} // namespace carla
