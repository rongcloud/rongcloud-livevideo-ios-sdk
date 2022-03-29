//
//  RCLiveVideoDelegate.h
//  RCE
//
//  Created by 叶孤城 on 2021/9/3.
//

#import <Foundation/Foundation.h>
#import <CoreMedia/CMSampleBuffer.h>

#import "RCLiveVideoDefine.h"

NS_ASSUME_NONNULL_BEGIN

@class RCMessage, RCRTCMixConfig;
@protocol RCLiveVideoDelegate <NSObject>

@optional

/// 房间信息已同步
- (void)roomInfoDidSync;

/// 房间信息更新
/// @param key 房间信息属性
/// @param value 房间信息内容
- (void)roomInfoDidUpdate:(NSString *)key value:(NSString *)value;

/// @param userId 用户进入房间
- (void)userDidEnter:(NSString *)userId withUserCount:(NSInteger)count;

/// @param userId 用户离开房间
- (void)userDidExit:(NSString *)userId withUserCount:(NSInteger)count;

/// @param userId 用户被踢出房间
- (void)userDidKickOut:(NSString *)userId byOperator:(NSString *)operatorId;

/// 房间连麦用户更新：用户上麦、下麦等
/// @param userIds 连麦的用户
- (void)liveVideoUserDidUpdate:(NSArray<NSString *> *)userIds;

/// 上麦申请列表发生变化
- (void)liveVideoRequestDidChange;

/// 申请上麦被同意：只有申请者收到回调
- (void)liveVideoRequestDidAccept;

/// 申请上麦被拒绝：只有申请者收到回调
- (void)liveVideoRequestDidReject;

/// 接收到上麦邀请：只有受邀请者收到回调
- (void)liveVideoInvitationDidReceive:(NSString *)inviter atIndex:(NSInteger)index;

/// 邀请上麦已被取消：只有受邀请者收到回调
- (void)liveVideoInvitationDidCancel;

/// 邀请上麦被同意
- (void)liveVideoInvitationDidAccept:(NSString *)invitee;

/// 邀请上麦被拒绝
- (void)liveVideoInvitationDidReject:(NSString *)invitee;

/// 直播连麦开始，通过申请、邀请等方式成功上麦后，接收回调。
- (void)liveVideoDidBegin:(RCLiveVideoCode)code;

/// 直播连麦结束
- (void)liveVideoDidFinish:(RCLiveVideoFinishReason)reason;

/// 收到消息
/// @param message 消息
- (void)messageDidReceive:(RCMessage *)message;

/// 网络状态延迟
/// @param delay 延迟时间:ms
- (void)network:(NSInteger)delay;

/// 视频输出回调，可以在此接口做视频流二次开发，例如：美颜。
/// @param sampleBuffer 视频流采样数据
- (nullable CMSampleBufferRef)didOutputSampleBuffer:(nullable CMSampleBufferRef)sampleBuffer DEPRECATED_MSG_ATTRIBUTE("use didOutputFrame: instead");

/// 视频流输出回调，可以在此接口做视频流二次开发，例如：美颜。
/// @param frame 视频帧数据
- (RCRTCVideoFrame *)didOutputFrame:(RCRTCVideoFrame *)frame;

/// 房间已关闭
- (void)roomDidClosed;

/// 视频连麦模式发生变化
/// @param mixType 连麦类型
- (void)roomMixTypeDidChange:(RCLiveVideoMixType)mixType;

@end

@protocol RCLiveVideoPKDelegate <NSObject>

@optional

/// 收到邀请 PK 的回调
/// @param inviterRoomId 邀请者的房间id
/// @param inviterUserId 邀请者的用户id
- (void)didReceivePKInvitationFromRoom:(NSString *)inviterRoomId byUser:(NSString *)inviterUserId;

/// 邀请者取消 PK 邀请回调
/// @param inviterRoomId 邀请者的房间id
/// @param inviterUserId 邀请者的用户id
- (void)didCancelPKInvitationFromRoom:(NSString *)inviterRoomId byUser:(NSString *)inviterUserId;

/// PK 邀请被同意回调
/// @param inviteeRoomId 被邀请者的房间id
/// @param inviteeUserId 被邀请者的用户id
- (void)didAcceptPKInvitationFromRoom:(NSString *)inviteeRoomId
                               byUser:(NSString *)inviteeUserId;

/// PK 邀请被拒绝回调
/// @param inviteeRoomId 被邀请者的房间id
/// @param inviteeUserId 被邀请者的用户id
/// @param reason 原因
- (void)didRejectPKInvitationFromRoom:(NSString *)inviteeRoomId
                               byUser:(NSString *)inviteeUserId
                               reason:(NSString *)reason;

/// PK 连接成功时触发此回调
- (void)didBeginPK:(RCLiveVideoCode)code;

/// 对方结束 PK 时触发此回调
/// 注意：收到该回调后会自动退出 PK 连接
- (void)didFinishPK:(RCLiveVideoCode)code;

@end

@protocol RCLiveVideoMixDataSource <NSObject>

@optional

/// 合流画布尺寸，使用 RCLiveVideoMixTypeCustom 模式时，必须实现！！！
- (CGSize)liveVideoPreviewSize;

/// 连麦布局对应的麦位位置数组：Array<CGRect>，使用 RCLiveVideoMixTypeCustom 模式时，必须实现！！！
- (NSArray<NSValue *> *)liveVideoFrames;

/// 合流帧率
- (NSInteger)fps;

/// 合流码率
- (NSInteger)bitrate;

@end

@class RCLiveVideoSeat;
@protocol RCLiveVideoMixDelegate <NSObject>

/// 自定义麦位视图
/// @param seat 麦位对象
/// @param frame 麦位在 previewView 中的位置
- (void)liveVideoDidLayout:(RCLiveVideoSeat *)seat withFrame:(CGRect)frame;

/// 合流布局配置将要更新
/// 开发者可以在此修改合流配置：
/// 视频：帧率、码率、背景等
/// 音频：码率等
/// @param config 配置对象
- (void)roomMixConfigWillUpdate:(RCRTCMixConfig *)config;

@end

NS_ASSUME_NONNULL_END
