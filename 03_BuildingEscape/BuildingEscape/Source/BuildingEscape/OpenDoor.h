// Copyright Julien Salamin 2017

#pragma once

#include "Components/ActorComponent.h"
#include "OpenDoor.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BUILDINGESCAPE_API UOpenDoor : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UOpenDoor();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	void OpenDoor();
	void CloseDoor();

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

private:
	UPROPERTY(EditAnywhere)
	float OpenAngle = 90.0f;

	UPROPERTY(EditAnywhere)
	float CloseAngle = 0.0f;

	UPROPERTY(EditAnywhere)
	float CloseDoorDelay = 1.f;
	
	UPROPERTY(EditAnywhere)
	ATriggerVolume* PressurePlate;

	float LastDoorOpenTime;

	AActor* Owner;

	// Returns total mass in kg
	float GetTotalMassOfActorsOnPlate();
};
