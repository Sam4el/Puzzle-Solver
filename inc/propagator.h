#pragma once

class IPropagator {
 public:
  virtual ~IPropagator() = default;
  // TODO arguments
  virtual void propagate() = 0;
};
