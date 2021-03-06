/*
 * Copyright (C)    Tony Josi
 * Date             19-05-2020
 */

#ifndef _CVD19SSIM_CORE_H
#define _CVD19SSIM_CORE_H

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

#ifndef EXIT_SUCCESS
#define EXIT_SUCCESS                    0
#endif

#ifndef EXIT_FAILURE
#define EXIT_FAILURE                    (-1)
#endif

typedef enum {
    CVD19SSIM_SUCCESS = 0,
    CVD19SSIM_PROGRESS,
    CVD19SSIM_FAIL,
    CVD19SSIM_INVLD_PARAMS,
    CVD19SSIM_INIT_FAIL,
    CVD19SSIM_MISC_FAIL

} CVD19SSIM_STATUS_t;

typedef struct _position {
    uint32_t x;
    uint32_t y;
} position_t;

typedef struct _speed {
    int x;
    int y;
} speed_t;

typedef struct _cvd19ssim_entity_mvmnt {

    position_t      cur_pos;
    speed_t         speed;

} cvd19ssim_entity_mvmnt_t;

typedef struct _cur_population_stat {

    uint32_t max_allowed_population_in_city;
    uint32_t cur_population;
    uint32_t total_population;
    uint32_t total_infected;
    uint32_t total_recovered;
    uint32_t total_infected_n_died;
    uint32_t total_new_births;
    uint32_t total_normal_deaths;

} cur_population_stat_t;

typedef struct _cvd19ssim_core_covid_entity_report {

    bool is_infected;
    bool is_quarantined;
    bool is_recovered;
    bool is_hospitalized;
    bool have_symptoms;
    bool is_tested;
    uint8_t days_of_infections;

} cvd19ssim_core_covid_entity_report_t;


typedef struct _entity_health_record {

    cvd19ssim_entity_mvmnt_t                pos_data;
    cvd19ssim_core_covid_entity_report_t    entity_cvd_report;
    uint32_t                                days_alive;
    bool                                    is_alive;
    uint8_t                                 prob_early_death;
    uint8_t                                 prob_better_immunity;

} entity_health_record_t;


typedef struct _cvd19ssim_core {

    uint32_t                city_space;
    cur_population_stat_t   population_data;
    entity_health_record_t  *entities;
    uint32_t                num_of_hospitals_in_city;
    uint32_t                capacity_per_hospital;
    position_t              *hospital_locations;
    uint32_t                cur_filled_hospital_capacity;
    uint32_t                max_spread_distance;
    uint32_t                initialy_infected;
    uint32_t                max_testing_capacity;
    uint32_t                days_passed;
    uint8_t                 avg_death_rate;
    uint8_t                 avg_birth_rate;

} cvd19ssim_core_t;

#define RAND_GEN(N)                     ((int)((double)rand() / ((double)RAND_MAX + 1) * N))

#define UNUSED(X)                       (void)X      /* To avoid gcc/g++ warnings */

#define MAG(N)                          ((N < 0) ? ((-1) * N) : N)

CVD19SSIM_STATUS_t cvd19ssim_RUNNER_MAIN();
CVD19SSIM_STATUS_t cvd19ssim_core_t_init(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_core_t_init_entities(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_normal_deaths(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_normal_births(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_covid_infections(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_covid_deaths(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_daily_summary_calc(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_daily_diagnosis(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_daily_recovery(cvd19ssim_core_t *);
CVD19SSIM_STATUS_t cvd19ssim_log_per_day_report(cvd19ssim_core_t *, FILE *);
#endif /* _CVD19SSIM_CORE_H */

