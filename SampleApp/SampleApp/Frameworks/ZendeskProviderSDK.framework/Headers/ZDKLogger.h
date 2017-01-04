/*
 *
 *  ZDKLogger.h
 *  ZendeskSDK
 *
 *  Created by Zendesk on 25/11/2014.  
 *
 *  Copyright (c) 2014 Zendesk. All rights reserved.
 *
 *  By downloading or using the Zendesk Mobile SDK, You agree to the Zendesk Master
 *  Subscription Agreement https://www.zendesk.com/company/customers-partners/#master-subscription-agreement and Application Developer and API License
 *  Agreement https://www.zendesk.com/company/customers-partners/#application-developer-api-license-agreement and
 *  acknowledge that such terms govern Your use of and access to the Mobile SDK.
 *
 */

#import <Foundation/Foundation.h>

/**
 *  Log level enum.
 */
typedef NS_ENUM(NSUInteger, ZDKLogLevel){

    /**
     *  Error logging.
     */
    ZDKLogLevelError        = 0,

    /**
     *  Warning logging.
     */
    ZDKLogLevelWarn         = 1,

    /**
     *  Info logging.
     */
    ZDKLogLevelInfo         = 2,

    /**
     *  Debug logging.
     */
    ZDKLogLevelDebug        = 3,

    /**
     *  Verbose logging.
     */
    ZDKLogLevelVerbose      = 4
};


/**
 *  Logger for SDK.
 */
@interface ZDKLogger : NSObject


/**
 *  Log an error message.
 *
 *  @param format format string for log message.
 */
+ (void) e:(NSString *)format, ...;

/**
 *  Log an error message.
 *
 *  @param logMessage the string for log message.
 */
+ (void) error:(NSString *)logMessage;

/**
 *  Log a warning message.
 *
 *  @param format format string for log message.
 */
+ (void) w:(NSString *)format, ...;

/**
 *  Log a warning message.
 *
 *  @param logMessage the string for log message.
 */
+ (void) warn:(NSString *)logMessage;

/**
 *  Log an info message.
 *
 *  @param format format string for log message.
 */
+ (void) i:(NSString *)format, ...;

/**
 *  Log an info message.
 *
 *  @param logMessage the string for log message.
 */
+ (void) info:(NSString *)logMessage;

/**
 *  Log a debug message.
 *
 *  @param format format string for log message.
 */
+ (void) d:(NSString *)format, ...;

/**
 *  Log a debug message.
 *
 *  @param logMessage the string for log message.
 */
+ (void) debug:(NSString *)logMessage;

/**
 *  Log a verbose message.
 *
 *  @param format format string for log message.
 */
+ (void) v:(NSString *)format, ...;

/**
 *  Log a verbose message.
 *
 *  @param logMessage the string for log message.
 */
+ (void) verbose:(NSString *)logMessage;


/**
 *  Set logger enabled
 *
 *  @param enabled enable ZDKLogger with YES, disable with NO.
 */
+ (void) enable:(BOOL)enabled;


/**
 *  Set the log level.
 *
 *  @param level A ZDKLogLevel enum value.
 */
+ (void) setLogLevel:(ZDKLogLevel)level;

/**
 *  Get the current log level.
 *
 *  @return The log level, a ZDKLogLevel enum value.
 */
+ (ZDKLogLevel) logLevel;


@end
