#include <chrono>

#include "stopwatch.h"

Stopwatch::Stopwatch()
{
    this->hasStarted = this->hasStoped = false;
    this->startTimestamp = this->stopTimestamp = std::chrono::high_resolution_clock::now();
}

Stopwatch::~Stopwatch()
{

}

constexpr const bool Stopwatch::getHasStarted()
{
    return this->hasStarted;
}

constexpr const bool Stopwatch::getHasStoped()
{
    return this->hasStoped;
}

constexpr const long double Stopwatch::getDuration()
{
    if (!this->hasStarted || !this->hasStoped)
    {
        throw std::runtime_error("Exception in Stopwatch.getDuration(): Stopwatch has not yet started or stoped");
    }

    return std::chrono::duration_cast<std::chrono::nanoseconds>(this->stopTimestamp - this->startTimestamp).count() * 1e-9;
}

void Stopwatch::start()
{
    if (this->hasStarted)
    {
        throw std::runtime_error("Exception in Stopwatch.getDuration(): Stopwatch has already started");
    }

    this->startTimestamp = std::chrono::high_resolution_clock::now();
    this->hasStarted = true;
}

void Stopwatch::stop()
{
    if (this->hasStoped || !this->hasStarted)
    {
        throw std::runtime_error("Exception in Stopwatch.getDuration(): Stopwatch has already stoped or has not yet started");
    }

    this->stopTimestamp = std::chrono::high_resolution_clock::now();
    this->hasStoped = true;
}

void Stopwatch::reset()
{
    if (!this->hasStarted && !this->hasStoped)
    {
        throw std::runtime_error("Exception in Stopwatch.getDuration(): Stopwatch is already in a reset state");
    }

    this->startTimestamp = this->stopTimestamp = std::chrono::high_resolution_clock::now();
    this->hasStarted = this->hasStoped = false;
}