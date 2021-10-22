//
//  RCLiveVideoDelegate.h
//  RCE
//
//  Created by 叶孤城 on 2021/9/3.
//

#import <Foundation/Foundation.h>
#import <AVFoundation/AVFoundation.h>
#import "RCLiveVideoErrorCode.h"

NS_ASSUME_NONNULL_BEGIN

@class RCMessage;
@protocol RCLiveVideoDelegate <NSObject>

@optional

/// 房间信息已同步
- (void)roomInfoDidSync;

/// 房间信息更新
/// @param key 房间信息属性
/// @param value 房间信息内容
- (void)roomInfoDidUpdate:(NSString *)key value:(NSString *)value;

/// @param userId 用户进入房间
- (void)userDidEnter:(NSString *)userId;

/// @param userId 用户离开房间
- (void)userDidExit:(NSString *)userId;

/// @param userId 用户被踢出房间
- (void)userDidKickOut:(NSString *)userId byOperator:(NSString *)operatorId;

/// 房间连麦用户更新：用户上麦、下麦等
/// @param userIds 连麦的用户
- (void)liveVideoDidUpdate:(NSArray<NSString *> *)userIds;

/// 上麦申请列表发生变化
- (void)liveVideoRequestDidChange;

/// 申请上麦被同意：只有申请者收到回调
- (void)liveVideoRequestDidAccept;

/// 申请上麦被拒绝：只有申请者收到回调
- (void)liveVideoRequestDidReject;

/// 接收到上麦邀请：只有受邀请者收到回调
- (void)liveVideoInvitationDidReceive;

/// 邀请上麦已被取消：只有受邀请者收到回调
- (void)liveVideoInvitationDidCancel;

/// 邀请上麦被同意
- (void)liveVideoInvitationDidAccept:(NSString *)userId;

/// 邀请上麦被拒绝
- (void)liveVideoInvitationDidReject:(NSString *)userId;

/// 直播连麦开始，通过申请、邀请等方式成功上麦后，接收回调。
- (void)liveVideoDidBegin:(RCLiveVideoErrorCode)code;

/// 直播连麦结束
- (void)liveVideoDidFinish;

/// 收到消息
/// @param message 消息
- (void)messageDidReceive:(RCMessage *)message;

/// 网络状态延迟
/// @param delay 延迟时间:ms
- (void)network:(NSInteger)delay;

/// 视频输出回调，可以在此接口做视频流二次开发，例如：美颜。
/// @param sampleBuffer 视频流采样数据
- (nullable CMSampleBufferRef)didOutputSampleBuffer:(nullable CMSampleBufferRef)sampleBuffer;

/// 合流视频点击事件，点击直播用户时触发
/// 注意：
/// 请确保在布局preview时，可点击用户的视图不被遮挡。
/// 如果preview被遮挡，请使用didLiveVideoLayout自定义事件点击视图
/// @param userId 被点击的用户id
- (void)liveVideoUserDidClick:(NSString *)userId;

/// 当视频布局发生变化时，更新直播用户的位置
/// @param frameInfo 直播用户布局信息
/// 格式为：[userId: frame]，userId：用户id，frame：用户在preview的位置
- (void)liveVideoUserDidLayout:(NSDictionary<NSString *, NSValue *> *)frameInfo;

/// 房间已关闭
- (void)roomDidClosed;

@end

NS_ASSUME_NONNULL_END
