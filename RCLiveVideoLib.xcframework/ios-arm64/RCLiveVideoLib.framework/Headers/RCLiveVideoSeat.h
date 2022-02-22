//
//  RCLiveVideoSeat.h
//  RCLiveVideoLib
//
//  Created by shaoshuai on 2021/11/21.
//

#import <UIKit/UIKit.h>

#import "RCLiveVideoDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class RCLiveVideoSeat;
@protocol RCLiveVideoSeatDelegate <NSObject>

/// 麦位锁定状态更新
/// @param seat 麦位
/// @param isLocked 是否锁定
- (void)seat:(RCLiveVideoSeat *)seat didLock:(BOOL)isLocked;

/// 麦位静音状态更新
/// @param seat 麦位
/// @param isMuted 是否静音
- (void)seat:(RCLiveVideoSeat *)seat didMute:(BOOL)isMuted;

/// 麦位用户音频状态更新
/// @param seat 麦位
/// @param enable 是否开启
- (void)seat:(RCLiveVideoSeat *)seat didUserEnableAudio:(BOOL)enable;

/// 麦位用户视频状态更新
/// @param seat 麦位
/// @param enable 是否开启
- (void)seat:(RCLiveVideoSeat *)seat didUserEnableVideo:(BOOL)enable;

/// 麦位声音状态更新
/// @param seat 麦位
/// @param audioLevel 声音大小
- (void)seat:(RCLiveVideoSeat *)seat didSpeak:(NSInteger)audioLevel;

@end

@interface RCLiveVideoSeat : NSObject

@property (nonatomic, weak) id<RCLiveVideoSeatDelegate> delegate;

/// 麦位上的用户
@property (nonatomic, copy, readonly) NSString *userId;

/// 麦上用户是否开启音频
@property (nonatomic, assign, readonly) BOOL userEnableAudio;

/// 麦上用户是否开启视频
@property (nonatomic, assign, readonly) BOOL userEnableVideo;

/// 麦位是否静音
@property (nonatomic, assign, readonly) BOOL mute;
/// 麦位是否锁住
@property (nonatomic, assign, readonly) BOOL lock;
/// 麦位在视频中的相对位置
@property (nonatomic, assign, readonly) CGRect frame;
/// 麦位序号
@property (nonatomic, assign, readonly) NSInteger index;
/// 控制本端订阅分流时是否采用小流，默认为 YES
@property (nonatomic, assign) BOOL enableTiny;

- (instancetype)initWith:(CGRect)frame
                   index:(NSInteger)index;

- (instancetype)initWith:(NSString *)userId
                    mute:(BOOL)mute
                    lock:(BOOL)lock
                   frame:(CGRect)frame
                   index:(NSInteger)index
         userEnableAudio:(BOOL)userEnableAudio
         userEnableVideo:(BOOL)userEnableVideo;

/// 锁定麦位
/// @param lock 是否锁定
/// @param completion 结果回调
- (void)setLock:(BOOL)lock completion:(RCLVResult)completion;
/// 静音麦位
/// @param mute 是否静音
/// @param completion 结果回调
- (void)setMute:(BOOL)mute completion:(RCLVResult)completion;
/// 设置用户音频状态
/// @param enable 是否开启
/// @param completion 结果回调
- (void)setUserEnableAudio:(BOOL)enable completion:(RCLVResult)completion;
/// 设置用户视频状态
/// @param enable 是否开启
/// @param completion 结果回调
- (void)setUserEnableVideo:(BOOL)enable completion:(RCLVResult)completion;

@end

NS_ASSUME_NONNULL_END
