#ifndef PARTICLEFILTER_H
#define PARTICLEFILTER_H

#include <random>
#include "Math.h"

class ParticleFilter
{
public:
    ParticleFilter();
	virtual ~ParticleFilter();
    void init(const cv::Mat& image, const cv::Rect& bbox);
    void update(const cv::Mat& image);
    void get_color_model(const cv::Mat& patch, std::vector<float>& model);
    float distance(const std::vector<float>& v1, const std::vector<float>& v2);
    float likelihood(const cv::Mat& patch);
    void transition(const cv::Mat& image); // pass the whole image
    void resample();
    void draw(cv::Mat& image);
    bool is_init(){return m_init;}
    int get_particle_count(){return static_cast<int>(m_point_vector.size());}
private:
    bool m_init;
    float m_std;
    int m_box_size;
    std::vector<cv::Point> m_point_vector;
    std::vector<float> m_weight_vector;
    std::vector<float> m_color_template;
    std::mt19937 m_generator;
    std::normal_distribution<float> m_normal;
};

#endif // PARTICLEFILTER_H