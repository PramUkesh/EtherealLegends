// © 2014 - 2016 Soverance Studios
// http://www.soverance.com

// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at

// http://www.apache.org/licenses/LICENSE-2.0

// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "GameFramework/Actor.h"
#include "Gear/MasterGearList.h"
#include "EtherealGearManager.generated.h"

class AEtherealGearMaster;

UCLASS()
class ETHEREAL_API AEtherealGearManager : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEtherealGearManager(const FObjectInitializer& ObjectInitializer);

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	// The root component for this actor.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Default)
	USceneComponent* Root;

	// The root component for this actor.
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Default)
	UWorld* World;

	// Spawns a new Gear item, based on the Name
	UFUNCTION(BlueprintCallable, Category = Inventory)
	AEtherealGearMaster* CreateGear(EMasterGearList ItemToCreate);
};
