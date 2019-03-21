//
//  WUBAPush.h
//  WUBAPush
//
//  Created by wangzhongfeng on 16/3/14.
//  Copyright © 2016年 58ganji. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "WUBAPushMessage.h"

typedef enum : NSUInteger {
    WUBAPushErrorCodeFailOnPushNetwork = 1001,      /*网络错误*/
    WUBAPushErrorCodeFailOnLocationUnknown,         /*获取到的定位信息有误*/
    WUBAPushErrorCodeFailOnLocationDenied,          /*没有定位的权限*/
    WUBAPushErrorCodeRepeatBindingUser,             /*重复绑定用户*/
    WUBAPushErrorCodeInvalidateUserID,
    WUBAPushErrorCodeInvalidateMessageID,           /*消息ID错误，内部使用*/
    WUBAPushErrorCodeFailToUnBindUser,              /*解绑用户出错*/
    WUBAPushErrorCodeFailOnPushAuth,                /*push功能认证失败*/
    WUBAPushErrorCodeErrorToken,                /*token无效*/
    WUBAPushErrorCodeUnknownError,                  /*未知错误，内部使用*/
} WUBAPushErrorCode;
extern NSString * WUBAPushErrorDomain;

/**
 *  通知的各个name
 */
extern  NSString * WUBAPushDidBindDeviceIdNotification ;
extern  NSString * WUBAPushDidBindTokenNotification ;
extern  NSString * WUBAPushDidBindVoipTokenNotification;
extern  NSString * WUBAPushDidBindUserIdNotification ;
extern  NSString * WUBAPushDidReceiveMessageNotification;
extern  NSString * WUBAPushDidRaiseErrorNotification ;

typedef void(^WUBAPushDeviceIdCallback)(NSString * deviceId);
@class WUBAPush;
@protocol WUBAPushDelegate <NSObject>
@optional

/**
 *  获取到消息的回调
 *
 *  @param message 获取到的消息
 */
-(void)pushDidReceivedMessage:(WUBAPushMessage *)message;
/**
 *  当前产生的错误信息
 *
 */
-(void)pushOnError:(NSError *)error;
/**
 *  绑定token的回调
 *
 */
-(void)pushDidBindToken:(NSData *)tocken;
/**
 *  绑定deviceID的回调
 *
 */
-(void)pushDidBindDeviceId:(NSString *)deviceId;
/**
 *  绑定voiptoken的回调,注意这个回调是在注册之后立刻回调的，这里应该是注册之后直接回调的
 *
 */
-(void)pushDidBindVoipToken:(NSData *)voipToken;
@end
@interface WUBAPush : NSObject
/**
 *  初始化push的方法
 *
 *  @param appid           从服务器申请到的appid
 *  @param appKey          从服务器申请到的appkey
 *  @param pn              推广渠道号
 *  @param launchingOption 程序的唤醒信息，处理点击推送通知启动
 *  @param delegate        push的回调对象
 *  @param isProduction    是否是发布版本
 */
+(void)registerPushWithAppID:(NSString *)appid
                      appKey:(NSString *)appKey pn:(NSString *)pn
             launchingOption:(NSDictionary *)launchingOption
                pushDelegate:(id<WUBAPushDelegate>)delegate
            apsForProduction:(BOOL)isProduction;
/**
 *  初始化push的方法
 *
 *  @param appid           从服务器申请到的appid
 *  @param appKey          从服务器申请到的appkey
 *  @param pn              推广渠道号
 *  @param launchingOption 程序的唤醒信息，处理点击推送通知启动
 *  @param delegate        push的回调对象
 *  @param registVoip      是否注册voippush
 *  @param isProduction    是否是发布版本
 */
+(void)registerPushWithAppID:(NSString *)appid
                      appKey:(NSString *)appKey pn:(NSString *)pn
             launchingOption:(NSDictionary *)launchingOption
                pushDelegate:(id<WUBAPushDelegate>)delegate
                  registVoip:(BOOL)registVoip
            apsForProduction:(BOOL)isProduction NS_AVAILABLE_IOS(8_0);
/**
 *  初始化push的方法
 *
 *  @param appid           从服务器申请到的appid
 *  @param appKey          从服务器申请到的appkey
 *  @param pn              推广渠道号
 *  @param types           推送类型
 *  @param launchingOption 程序的唤醒信息，处理点击推送通知启动
 *  @param delegate        push的回调对象
 *  @param isProduction    是否是发布版本
 */
+(void)registerPushWithAppID:(NSString *)appid
                      appKey:(NSString *)appKey
                          pn:(NSString *)pn
                   pushTypes:(NSInteger)types
             launchingOption:(NSDictionary *)launchingOption
                pushDelegate:(id<WUBAPushDelegate>)delegate
            apsForProduction:(BOOL)isProduction;
/**
 *  初始化push的方法
 *
 *  @param appid           从服务器申请到的appid
 *  @param appKey          从服务器申请到的appkey
 *  @param pn              推广渠道号
 *  @param types           推送类型
 *  @param launchingOption 程序的唤醒信息，处理点击推送通知启动
 *  @param registVoip      是否注册voippush
 *  @param delegate        push的回调对象
 *  @param isProduction    是否是发布版本
 */
+(void)registerPushWithAppID:(NSString *)appid
                      appKey:(NSString *)appKey
                          pn:(NSString *)pn
                   pushTypes:(NSInteger)types
             launchingOption:(NSDictionary *)launchingOption
                pushDelegate:(id<WUBAPushDelegate>)delegate
                  registVoip:(BOOL)registVoip
            apsForProduction:(BOOL)isProduction NS_AVAILABLE_IOS(8_0);

/**
 *
 *  初始化push的方法，注意本方法不注册推送服务,只做相关的准备工作
 *
 *  @param appid           从服务器申请到的appid
 *  @param appKey          从服务器申请到的appkey
 *  @param pn              推广渠道号
 *  @param launchingOption 程序的唤醒信息，处理点击推送通知启动
 *  @param delegate        push的回调对象
 *  @param isProduction    是否是发布版本
 */
+(void)preparePushWithAppID:(NSString *)appid appKey:(NSString *)appKey pn:(NSString *)pn launchingOption:(NSDictionary *)launchingOption pushDelegate:(id<WUBAPushDelegate>)delegate apsForProduction:(BOOL)isProduction;
/**
 *  获取到devicetoken之后必须调用本方法将token传入
 *
 *  @param deviceToken 获取到的devicetoken
 */
+ (void)registerDeviceToken:(NSData *)deviceToken;
/**
 *  获取到的通知需要传入处理之后才能返回
 *  iOS7以后推荐使用
    - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult result))completionHandler
 * iOS7以前使用
    - (void)application:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo
    注意如果实现了application:didReceiveRemoteNotification:fetchCompletionHandler:的话在iOS7以后这个方法不会被调用
 *  @param remoteInfo 获取到的通知
 */
+ (void)handleRemoteNotification:(NSDictionary *)remoteInfo;
/**
 *  绑定userid的接口，如果需要解绑传空即可
 *
 *  @param userId 当前的userid，直接覆盖旧的userid，如果传空则解绑之前的userid
 */
+ (void)bindUserId:(NSString *)userId;
/**
 *  当推送消息被用户响应了之后调用，主要用来做数据统计的
 *
 *  @param message 被用户响应的消息
 */
+ (void)clickedMessage:(WUBAPushMessage *)message;

/**
 *  获取当前的deviceID，只有当绑定用户的操作在后台做的时候才可以获取到数据，返回的字段有可能是空
 *
 */
+ (void)requestDeviceIdWithCompeletion:(WUBAPushDeviceIdCallback)callBack;
/**
 *  清空缓存信息
 */
+ (void)resetPush;
/**
 *  获取SDK的版本号
 *
 */
+ (NSString *)version;
/**
 *  绑定别名的接口，如果需要解绑传空即可
 *
 *  @param alias 当前的设备别名，直接覆盖别名，如果传空则解绑之前的设备别名，
 */
+ (void)bindAlias:(NSString *)alias;

#pragma mark = 本地通知

/**
 发送本地通知的方法

 @param identifier 本地通知的标识，建议设置一个有规律的方便撤销
 @param title iOS10可用，用来设置大标题
 @param subtitle iOS10可用，用来设置小标题
 @param body 推送展示的内容，即alertbody
 @param badge 角标
 @param soundName 播放声音的文件名，注意只能是bundle中的音乐文件名
 @param interval 发送延时时间
 @param repeat 是否重复，这里建议设置NO
 @param userInfo 透传的信息
 */
+(void)schedulePushWithIdentifier:(NSString *)identifier
                            title:(NSString *)title
                         subtitle:(NSString *)subtitle
                             body:(NSString *)body
                            badge:(NSInteger)badge
                        soundName:(NSString *)soundName
                     timeInterval:(NSTimeInterval)interval 
                          repeats:(BOOL)repeat 
                         userInfo:(NSDictionary*)userInfo;

/**
 撤销本地通知的方法

 @param identifier 需要撤销的通知的标识
 */
+ (void)cancelLocalNotificationWithIdentifier:(NSString *)identifier;

@end
