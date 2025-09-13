#pragma once

class Propagator {
 public:
  virtual ~Propagator() = default;
  // TODO arguments
  virtual void propagate() = 0;
};
