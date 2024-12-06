#include <algorithm>
#include <numeric>
#include <cmath>
#include "lock_utils/Fliters.h"  // 注意路径要和实际安装路径对应

// LowPassFilter implementation
LowPassFilter::LowPassFilter(double cutoff_frequency, double sampling_time)
    : alpha_(computeAlpha(cutoff_frequency, sampling_time)), prev_output_(0.0) {}

double LowPassFilter::filter(double input) {
    double output = alpha_ * input + (1.0 - alpha_) * prev_output_;
    prev_output_ = output;
    return output;
}

double LowPassFilter::computeAlpha(double cutoff_frequency, double sampling_time) {
    double rc = 1.0 / (2.0 * M_PI * cutoff_frequency);
    return sampling_time / (sampling_time + rc);
}

// MedianFilter implementation
MedianFilter::MedianFilter(int window_size) : window_size_(window_size) {}

double MedianFilter::filter(double input) {
    buffer_.push_back(input);
    if (buffer_.size() > static_cast<size_t>(window_size_)) {
        buffer_.erase(buffer_.begin());
    }

    std::vector<double> sorted_buffer = buffer_;
    std::sort(sorted_buffer.begin(), sorted_buffer.end());

    if (sorted_buffer.size() % 2 == 0) {
        int mid = sorted_buffer.size() / 2;
        return (sorted_buffer[mid - 1] + sorted_buffer[mid]) / 2.0;
    } else {
        return sorted_buffer[sorted_buffer.size() / 2];
    }
}

// MeanFilter implementation
MeanFilter::MeanFilter(int window_size) : window_size_(window_size) {}

double MeanFilter::filter(double input) {
    buffer_.push_back(input);
    if (buffer_.size() > static_cast<size_t>(window_size_)) {
        buffer_.erase(buffer_.begin());
    }

    return std::accumulate(buffer_.begin(), buffer_.end(), 0.0) / buffer_.size();
}
