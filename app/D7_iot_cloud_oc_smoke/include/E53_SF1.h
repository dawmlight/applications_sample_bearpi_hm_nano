/*
 * Copyright (c) 2020 Nanjing Xiaoxiongpai Intelligent Technology Co., Ltd.
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *    http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef __E53_SF1_H__
#define __E53_SF1_H__

typedef enum
{
	OFF = 0,
	ON
} E53SF1Status;

void E53SF1Init(void);
void MQ2PPMCalibration(void);
int GetMQ2PPM(float *ppm);
void BeepStatusSet(E53SF1Status status);

#endif /* __E53_SF1_H__ */

