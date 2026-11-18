# Unitree Go2 BOUND gait policy
Front legs together, then back legs. Trained in Isaac Lab (unitree_rl_lab), flat ground, model 2700. Tested on a real Go2 EDU.
Speed range: 0.6 - 1.2 m/s forward (it only learned these speeds and standing still), turning +-0.5 rad/s.

Files: exported/policy.onnx (+ policy.onnx.data, keep both together), params/deploy.yaml, go2_ctrl_bound_joystick.cpp.

ONE-TIME SETUP: this policy uses a special remote input "bound_velocity_commands".
  Add the code in go2_ctrl_bound_joystick.cpp to the END of
  unitree_rl_lab/deploy/robots/go2/src/State_RLBase.cpp, then rebuild:
  cd unitree_rl_lab/deploy/robots/go2/build && make -j8

How to run:
1. In unitree_rl_lab/deploy/robots/go2/config/config.yaml set  policy_dir: /full/path/to/go2-flat-trot-policy/bound
2. Robot lying down, sport mode released (low-level mode), Ethernet connected.
3. cd unitree_rl_lab/deploy/robots/go2/build && ./go2_ctrl --network <ethernet-name>
   (if it crashes and ROS 2 is installed: env -u LD_LIBRARY_PATH ./go2_ctrl --network <ethernet-name>)
4. LT+A = stand, Start = policy, LT+B = EMERGENCY STOP.
5. Left stick centred = stand. Left stick pushed forward = bound at 0.6 m/s (more push = faster, up to 1.2 m/s).
   Right stick = turn (only while moving).

The bound is fast and dynamic: FLAT FLOOR ONLY, at least 5 m of free space, harness on, the rope holder walks along.
