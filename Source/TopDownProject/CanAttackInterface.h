#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "CanAttackInterface.generated.h"

UINTERFACE(BlueprintType)
class TOPDOWNPROJECT_API UCanAttackInterface : public UInterface
{
    GENERATED_BODY()
};

class TOPDOWNPROJECT_API ICanAttackInterface
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Attack")
    void StartAttack();

    UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Attack")
    void EndAttack();
};
