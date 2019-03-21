//
//  WPushLocalNotification.h
//  WUBAPush
//
//  Created by whisper on 16/12/21.
//  Copyright © 2016年 58ganji. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface WPushLocalNotification : NSObject
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
