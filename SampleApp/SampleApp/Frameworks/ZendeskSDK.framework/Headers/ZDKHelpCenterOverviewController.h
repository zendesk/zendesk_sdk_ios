/*
 *
 *  ZDKHelpCenterOverviewController.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 27/05/2016.
 *
 *  Copyright © 2016 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <UIKit/UIKit.h>
#import "ZDKHelpCenterConversationsUIDelegate.h"
#import "ZDKHelpCenterOverviewContentModel.h"

NS_ASSUME_NONNULL_BEGIN
NS_AVAILABLE_IOS(8_0)


/**
 *  Displays Help Center content.
 */
@interface ZDKHelpCenterOverviewController : UIViewController

@property (nonatomic, weak) id<ZDKHelpCenterConversationsUIDelegate> uiDelegate;

- (instancetype) initWithHelpCenterOverviewModel:(ZDKHelpCenterOverviewContentModel *)helpCenterContentModel;

@end
NS_ASSUME_NONNULL_END
