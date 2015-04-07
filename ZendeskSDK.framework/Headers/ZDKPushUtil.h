/*
 *
 *  ZDKPushUtil.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 19/03/2015.
 *
 *  Copyright (c) 2015 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Terms
 *  of Service https://www.zendesk.com/company/terms and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/application-developer-and-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

/**
 *  ZDKPushUtil handles push notifications for Zendesk SDK related notifications.
 *  
 *  @since 1.2.0.1
 */
@interface ZDKPushUtil : NSObject

/**
 *  Handles a remote notification for Zendesk SDK related notifications.
 *  This handler attempt to pull out a request id from the push info
 *  dictionary and use this to fetch the updated ticket.
 *
 *  @since 1.2.0.1
 *
 *  @param pushInfo          The info dictionary from the app delegate remote notification methods.
 *  @param application       The application.
 *  @param presentationStyle The presentation style for a modally presented view.
 *  @param guide             A layout guid for the presented view controller.
 *  @param applicationId     The application ID. The same as in the ZDKConfig initialize method.
 *  @param zendeskUrl        Your Zendesk url. The same as in the ZDKConfig initialize method.
 *  @param oAuthClientId     The OAuth client ID. The same as in the ZDKConfig initialize method.
 */
+ (void) handlePush:(NSDictionary *)pushInfo
     forApplication:(UIApplication *)application
  presentationStyle:(UIModalPresentationStyle)presentationStyle
        layoutGuide:(ZDKLayoutGuide)guide
          withAppId:(NSString *)applicationId
         zendeskUrl:(NSString *)zendeskUrl
           clientId:(NSString *)oAuthClientId;


/**
 *  Handles a remote notification for Zendesk SDK related notifications. 
 *  This handler attempt to pull out a request id from the push info 
 *  dictionary and use this to fetch the updated ticket.
 *
 *  @since 1.2.0.1
 *
 *  @param pushInfo          The info dictionary from the app delegate remote notification methods.
 *  @param application       The application.
 *  @param presentationStyle The presentation style for a modally presented view.
 *  @param guide             A layout guid for the presented view controller.
 *  @param applicationId     The application ID. The same as in the ZDKConfig initialize method.
 *  @param zendeskUrl        Your Zendesk url. The same as in the ZDKConfig initialize method.
 *  @param oAuthClientId     The OAuth client ID. The same as in the ZDKConfig initialize method.
 *  @param completionHandler The fetch completion handler from the app delegate remote notification method.
 */
+ (void) handlePush:(NSDictionary *)pushInfo
     forApplication:(UIApplication *)application
  presentationStyle:(UIModalPresentationStyle)presentationStyle
        layoutGuide:(ZDKLayoutGuide)guide
          withAppId:(NSString *)applicationId
         zendeskUrl:(NSString *)zendeskUrl
           clientId:(NSString *)oAuthClientId fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

@end
