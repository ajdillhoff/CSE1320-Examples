#pragma once

class Automobile {
    public:
        // Pure virtual -- classes inheriting this MUST define this function
        virtual double speed() const = 0;
        virtual void Accelerate() = 0;
        virtual ~Automobile() {}
};
