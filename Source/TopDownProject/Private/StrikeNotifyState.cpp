#include "StrikeNotifyState.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Actor.h"
#include "../CanAttackInterface.h"

void UStrikeNotifyState::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration, const FAnimNotifyEventReference& EventReference)
{
    if (!MeshComp) return;

    AActor* Owner = MeshComp->GetOwner();
    if (!Owner) return;

    if (Owner->GetClass()->ImplementsInterface(UCanAttackInterface::StaticClass()))
    {
        ICanAttackInterface::Execute_StartAttack(Owner);
    }
}

void UStrikeNotifyState::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, const FAnimNotifyEventReference& EventReference)
{
    if (!MeshComp) return;

    AActor* Owner = MeshComp->GetOwner();
    if (!Owner) return;

    if (Owner->GetClass()->ImplementsInterface(UCanAttackInterface::StaticClass()))
    {
        ICanAttackInterface::Execute_EndAttack(Owner);
    }
}
