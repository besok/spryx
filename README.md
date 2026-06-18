Spatial Dynamics Kernel
A clean, header-only, zero-dependency **C++20** implementation of rigid-body dynamics for serial robot manipulators — **Recursive Newton-Euler (RNEA)** for inverse dynamics and **Featherstone's Articulated Body Algorithm (ABA)** for forward dynamics.
Built to be *readable*: a reference you can learn spatial dynamics from, and drop into a standalone or RTOS project without dragging in ROS, Pinocchio, or Eigen.
## Why
Pinocchio is the industry standard but is hard to read (deep CRTP + Eigen) and slow to compile. Extracting dynamics for a standalone Jetson or embedded target means fighting framework dependencies. This fills the gap: a **readable, zero-dependency, fast-compiling** alternative — not faster than Pinocchio, but far easier to understand, integrate, and vendor.
## Scope
- **Inverse dynamics (RNEA):** given joint positions/velocities/accelerations → joint torques.
- **Forward dynamics (ABA):** given joint torques → joint accelerations.
- **Joints:** 1-DOF only — **revolute and prismatic**. This is deliberate: it keeps articulated-inertia handling to scalar divisions (no runtime matrix inversion, no custom linear-algebra), covers most serial arms, and keeps the focus on clean C++ rather than numerical edge cases.
- **Topology:** fixed kinematic chains, defined at compile time.
  **Out of scope:** multi-DOF joints (spherical/floating base), contact/collision, beating Pinocchio on speed.
## Design
- Header-only, no heap allocation in the hot path.
- C++20 **concepts** (not CRTP) to define what a `Body` / `Joint` is.
- A small vendored spatial-algebra math header (Plücker coordinates, spatial inertia) — no Eigen.
- Fixed topology expressed via `constexpr` / templates.
## Trade-offs (honest)
Likely slower than Pinocchio (no Eigen SIMD expression templates). The trade is **compile speed + zero dependencies + readability** over peak runtime performance. Performance-critical teams should stick with Pinocchio; this is for learning and standalone/embedded integration.
## Status
In development. Built in order: spatial-algebra math header → `Body`/`Joint` types → RNEA → ABA → docs/examples.