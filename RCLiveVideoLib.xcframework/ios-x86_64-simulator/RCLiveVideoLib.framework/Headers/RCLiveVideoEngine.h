//
//  RCLiveVideoEngine.h
//  RCE
//
//  Created by 叶孤城 on 2021/9/2.
//

#import <RongRTCLib/RongRTCLib.h>

#import "RCLiveVideoDefine.h"
#import "RCLiveVideoCode.h"

NS_ASSUME_NONNULL_BEGIN

@protocol
RCLiveVideoDelegate,
RCLiveVideoMixDelegate,
RCLiveVideoMixDataSource;
@class RCLiveVideoSeat;
@interface RCLiveVideoEngine : NSObject

@property (nonatomic, readonly) NSString *roomId;
@property (nonatomic, readonly) RCRTCLiveRoleType currentRole;
@property (nonatomic, readonly) RCLiveVideoMixType currentMixType;
@property (nonatomic, readonly) NSArray<RCLiveVideoSeat *> *currentSeats;

@property (nonatomic, weak) id<RCLiveVideoDelegate> delegate;
@property (nonatomic, weak) id<RCLiveVideoMixDelegate> mixDelegate;
@property (nonatomic, weak) id<RCLiveVideoMixDataSource> mixDataSource;

+ (instancetype)shared;

@end

/// 房主
@interface RCLiveVideoEngine (host)

/// 房主准备直播，视频流回调
- (void)prepare;

/// 开始直播
/// @param roomId 房间id
/// @param completion 结果回调
- (void)begin:(NSString *)roomId completion:(nonnull RCLVResult)completion;

/// 结束直播并离开房间
/// 注意：
/// SDK 不具备关闭房间能力，请通过服务器接口关闭房间。请在关闭房间之前调用本方法。
/// @param completion 结果回调
- (void)finish:(nonnull RCLVResult)completion;

@end

/// 观众
@interface RCLiveVideoEngine (audience)

/// 加入房间，观众订阅RTC流
/// @param roomId 房间id
/// @param completion 结果回调
- (void)joinRoom:(nonnull NSString *)roomId
      completion:(nonnull RCLVResult)completion;

/// 加入房间，观众订阅CDN流
/// @param roomId 房间id
/// @param completion 结果回调
- (void)joinCDNRoom:(nonnull NSString *)roomId
         completion:(nonnull RCLVResult)completion;

/// 加入房间，观众订阅CDN流
/// 如果videoSizePreset或fps大于视频流的最大值，则使用最大值
/// @param roomId 房间id
/// @param videoSizePreset 视频大小
/// @param FPS 视频帧率
/// @param completion 结果回调
- (void)joinCDNRoom:(nonnull NSString *)roomId
    videoSizePreset:(RCRTCVideoSizePreset)videoSizePreset
                FPS:(RCRTCVideoFPS)FPS
         completion:(nonnull RCLVResult)completion;

/// 离开房间
/// @param completion 结果回调
- (void)leaveRoom:(nonnull RCLVResult)completion;

@end

@interface RCLiveVideoEngine (operation)

/// 加入连麦
/// @param index 麦位序号，当传入 -1 时，自动查找第一个空麦位
/// @param completion 结果回调
- (void)joinLiveVideoAtIndex:(NSInteger)index completion:(nonnull RCLVResult)completion;

/// 离开连麦
/// @param completion 结果回调
- (void)leaveLiveVideo:(nonnull RCLVResult)completion;

/// 请求视频直播，根据时间先后最多有10人等待
/// @param index 观众期望加入的位置。
/// 注意：
/// 麦位总数由连麦类型决定，比如：一对一场景，麦位数量为1；九宫格，麦位数量为9。
/// 如果，麦位传入为-1，那么，用户上麦时，SDK 会自动查询第一个空麦位。
/// @param completion 结果回调
- (void)requestLiveVideo:(NSInteger)index completion:(nonnull RCLVResult)completion;

/// 取消上麦请求
/// @param completion 结果回调
- (void)cancelRequest:(nonnull RCLVResult)completion;

/// 接受上麦请求
/// 如果上麦的麦位已被占用，SDK 会自动查询第一个空麦位。
/// @param userId 目标用户id
/// @param completion 结果回调
- (void)acceptRequest:(NSString *)userId completion:(nonnull RCLVResult)completion;

/// 拒绝上麦请求
/// @param userId 目标用户id
/// @param completion 结果回调
- (void)rejectRequest:(NSString *)userId completion:(nonnull RCLVResult)completion;

/// 获取当前申请上麦的所有用户
/// @param completion 结果回调
- (void)getRequests:(void(^)(RCLiveVideoCode code, NSArray<NSString *> *userIds))completion;

/// 邀请用户上麦
/// @param userId 目标用户id
/// @param index 邀请位置
/// 注意：
/// 麦位总数由连麦类型决定，比如：一对一场景，麦位数量为1；九宫格，麦位数量为9。
/// 如果麦位传入-1，SDK 会自动查询第一个空麦位。
/// @param completion 结果回调
- (void)inviteLiveVideo:(NSString *)userId atIndex:(NSInteger)index completion:(nonnull RCLVResult)completion;

/// 取消上麦邀请
/// @param userId 目标用户id
/// @param completion 结果回调
- (void)cancelInvitation:(NSString *)userId completion:(nonnull RCLVResult)completion;

/// 接受上麦邀请，并上麦
/// 如果上麦的麦位已被占用，SDK 会自动查询第一个空麦位。
/// @param completion 结果回调
- (void)acceptInvitationOfUser:(NSString *)userId atIndex:(NSInteger)index completion:(nonnull RCLVResult)completion;

/// 拒绝上麦邀请
/// @param completion 结果回调
- (void)rejectInvitationOfUser:(NSString *)userId completion:(nonnull RCLVResult)completion;

/// 获取当前邀请上麦的所有用户
/// @param completion 结果回调
- (void)getInvitations:(void(^)(RCLiveVideoCode code, NSArray<NSString *> *userIds))completion;

/// 切换座位，如果目标座位被占用，则返回失败
/// @param index 目标座位
/// @param completion 结果回调
- (void)switchLiveVideoTo:(NSInteger)index completion:(nonnull RCLVResult)completion;

/// 抱用户上麦
/// @param userId 停止视频直播的用户
/// @param index 麦位号
/// @param completion 结果回调
- (void)pickUserToSeat:(NSString *)userId
               atIndex:(NSInteger)index
            completion:(nonnull RCLVResult)completion;

/// 踢用户下麦
/// @param userId 视频连麦中的用户
/// @param completion 结果回调
- (void)kickUserFromSeat:(NSString *)userId
              completion:(nonnull RCLVResult)completion;

/// 更新房间自定义属性，建议属性数量<50
/// @param roomInfo 房间信息属性<key, value>
- (void)setRoomInfo:(NSDictionary<NSString *, NSString *> *)roomInfo completion:(nonnull RCLVResult)completion;

@end

@interface RCLiveVideoEngine (message)

/// 将用户踢出房间
/// @param userId 被踢出用户的id
/// @param completion 结果回调
- (void)kickOutRoom:(NSString *)userId completion:(nonnull RCLVResult)completion;

/// 发送直播房间消息
/// @param content 消息内容
/// @param completion 结果回调
- (void)sendMessage:(RCMessageContent *)content completion:(nonnull RCLVResult)completion;

@end

@interface RCLiveVideoEngine (view)

/// 直播视频页面
- (UIView *)previewView;

/// 设置视频合流布局类型
/// @param type 布局类型
/// @param completion 结果回调
- (void)setMixType:(RCLiveVideoMixType)type completion:(nonnull RCLVResult)completion;

@end

NS_ASSUME_NONNULL_END
