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

#ifndef __E53_SC1_H__
#define __E53_SC1_H__

#define BH1750_ADDR 0x23

typedef enum
{
	OFF = 0,
	ON
} E53SC1Status;

int E53SC1Init(void);
int E53SC1ReadData(float *data);
void LightStatusSet(E53SC1Status status);


#endif /* __E53_SC1_H__ */

