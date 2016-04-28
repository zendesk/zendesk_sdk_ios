/*
 *
 *  ZDKRotationForwarding.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 3/30/16.
 *
 *  Copyright © 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

@protocol ZDKRotationForwarding <NSObject>

- (void)orientationWillChange:(UIInterfaceOrientation)toInterfaceOrientation;

@end
