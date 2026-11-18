# Unitree Go2 flat-ground trot policy
Trained in Isaac Lab (unitree_rl_lab, flat terrain, 500 iterations). Tested on a real Go2 EDU.

Files: exported/policy.onnx (+ policy.onnx.data, keep both together) and params/deploy.yaml.

How to run (Go2 EDU + unitree_rl_lab go2_ctrl):
1. In unitree_rl_lab/deploy/robots/go2/config/config.yaml set  policy_dir: /full/path/to/go2-flat-trot-policy
2. Robot lying down, sport mode released (low-level mode), Ethernet connected.
3. cd unitree_rl_lab/deploy/robots/go2/build && ./go2_ctrl --network <ethernet-name>
   (if it crashes and ROS 2 is installed: env -u LD_LIBRARY_PATH ./go2_ctrl --network <ethernet-name>)
4. LT+A = stand, Start = policy, LT+B = EMERGENCY STOP.
5. Left stick = forward/back and sideways, right stick = turn.

FLAT FLOOR ONLY. Use a harness for the first test.

Also in this repo: bound/ = bound gait policy (see bound/README.md).
