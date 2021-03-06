/* Copyright (c) 2013-2015, The Linux Foundation. All rights reserved.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 and
 * only version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#ifndef MSM_CAMERA_DT_UTIL_H__
#define MSM_CAMERA_DT_UTIL_H__

#include <soc/qcom/camera2.h>
#include <linux/gpio.h>
#include <linux/of.h>
#include "msm_camera_i2c.h"

#define INVALID_VREG 100

#if 1// To check firmware in FROM
#define SYSFS_COMP_FW_PATH "/sys/class/camera/rear/rear_companionfw_full"
#define SYSFS_FW_CHECK_PATH "/sys/class/camera/rear/rear_fwcheck"
#define SYSFS_ISP_CORE_PATH "/sys/class/camera/rear/isp_core"

enum check_fw {
	CHECK_CAMERA_FW,
	CHECK_COMPANION_FW,
};

int msm_camera_write_sysfs(char* path, const char* data, uint32_t data_size);
int msm_camera_fw_check(const char read_fw_crc, uint8_t index);
#endif

int msm_sensor_get_sub_module_index(struct device_node *of_node,
	struct  msm_sensor_info_t **s_info);

int msm_sensor_get_dt_actuator_data(struct device_node *of_node,
	struct msm_actuator_info **act_info);

int msm_sensor_get_dt_csi_data(struct device_node *of_node,
	struct msm_camera_csi_lane_params **csi_lane_params);

int msm_camera_get_dt_power_setting_data(struct device_node *of_node,
	struct camera_vreg_t *cam_vreg, int num_vreg,
	struct msm_camera_power_ctrl_t *power_info);

int msm_camera_get_dt_gpio_req_tbl(struct device_node *of_node,
	struct msm_camera_gpio_conf *gconf, uint16_t *gpio_array,
	uint16_t gpio_array_size);

int msm_camera_init_gpio_pin_tbl(struct device_node *of_node,
	struct msm_camera_gpio_conf *gconf, uint16_t *gpio_array,
	uint16_t gpio_array_size);

int msm_camera_get_dt_vreg_data(struct device_node *of_node,
	struct camera_vreg_t **cam_vreg, int *num_vreg);

#if defined (CONFIG_CAMERA_SYSFS_V2)
int msm_camera_get_dt_camera_info(struct device_node *of_node, char *buf);
#endif

int msm_camera_power_up(struct msm_camera_power_ctrl_t *ctrl,
	enum msm_camera_device_type_t device_type,
	struct msm_camera_i2c_client *sensor_i2c_client);

int msm_camera_power_down(struct msm_camera_power_ctrl_t *ctrl,
	enum msm_camera_device_type_t device_type,
	struct msm_camera_i2c_client *sensor_i2c_client);

#if defined(CONFIG_SAMSUNG_QUICK_SWITCHING)
int msm_camera_power_up_adc(struct msm_camera_power_ctrl_t *ctrl,
	enum msm_camera_device_type_t device_type,
	struct msm_camera_i2c_client *sensor_i2c_client, int adc_mode);

int msm_camera_power_down_adc(struct msm_camera_power_ctrl_t *ctrl,
	enum msm_camera_device_type_t device_type,
	struct msm_camera_i2c_client *sensor_i2c_client, int adc_mode);
#endif

int msm_camera_fill_vreg_params(struct camera_vreg_t *cam_vreg,
	int num_vreg, struct msm_sensor_power_setting *power_setting,
	uint16_t power_setting_size);

#endif
