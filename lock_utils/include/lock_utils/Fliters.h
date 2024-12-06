#ifndef LOCK_UTILS_FILTERS_H
#define LOCK_UTILS_FILTERS_H

#include <vector>

class Filter {
public:
    virtual double filter(double input) = 0;
    virtual ~Filter() = default;
};

class LowPassFilter : public Filter {
public:
    LowPassFilter(double cutoff_frequency, double sampling_time);
    double filter(double input) override;

private:
    double computeAlpha(double cutoff_frequency, double sampling_time);
    double alpha_;
    double prev_output_;
};

class MedianFilter : public Filter {
public:
    explicit MedianFilter(int window_size);
    double filter(double input) override;

private:
    int window_size_;
    std::vector<double> buffer_;
};

class MeanFilter : public Filter {
public:
    explicit MeanFilter(int window_size);  // 这里之前写错了，是 MeanFilter 而不是 MedianFilter
    double filter(double input) override;

private:
    int window_size_;
    std::vector<double> buffer_;
};

#endif // LOCK_UTILS_FILTERS_H
