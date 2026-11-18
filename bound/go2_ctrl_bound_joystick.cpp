// Add this to unitree_rl_lab/deploy/robots/go2/src/State_RLBase.cpp (at the end), then rebuild:
//   cd unitree_rl_lab/deploy/robots/go2/build && make -j8
// Joystick velocity command for the bound policy (real Go2 remote).
// Left stick centred      -> 0 (stand still; the policy was trained to stand at exactly 0)
// Left stick forward      -> lin_vel_x range [min, max] from deploy.yaml (never the untrained gap 0..min)
// Right stick left/right  -> turn, only while moving (turning in place was not trained)
namespace isaaclab
{
REGISTER_OBSERVATION(bound_velocity_commands)
{
    auto & joystick = env->robot->data.joystick;
    auto r = env->cfg["commands"]["base_velocity"]["ranges"];
    const float vx_min = r["lin_vel_x"][0].as<float>();
    const float vx_max = r["lin_vel_x"][1].as<float>();
    const float wz_max = r["ang_vel_z"][1].as<float>();
    const float dead = 0.15f;

    const float ly = std::clamp(joystick->ly(), -1.0f, 1.0f);
    const float rx = std::clamp(-joystick->rx(), -1.0f, 1.0f);
    float vx = 0.0f, wz = 0.0f;
    if(ly > dead)
    {
        vx = vx_min + (ly - dead) / (1.0f - dead) * (vx_max - vx_min);
        if(std::fabs(rx) > dead)
            wz = std::copysign((std::fabs(rx) - dead) / (1.0f - dead), rx) * wz_max;
    }
    return {vx, 0.0f, wz};
}
}
