(function(){
  'use strict';window.Gym=window.Gym||{};
  const v2Styles=document.createElement('link');v2Styles.rel='stylesheet';v2Styles.href='assets/css/v2.css';document.head.append(v2Styles);
  Gym.log=function(action,entityType,entityId,description){Gym.state.activityLogs.unshift({id:Gym.Utils.id('log'),timestamp:new Date().toISOString(),action,entityType,entityId,description})};
  function initialize(){let state=Gym.Storage.load();if(!state){const v1=Gym.Storage.loadV1();try{state=v1?Gym.Migrations.toV2(v1):Gym.enhanceDemoV2(Gym.Migrations.toV2(Gym.createDemo()));Gym.state=state;Gym.Notifications.generate();const check=Gym.Integrity.check(state);if(!check.valid)throw new Error(check.errors[0]);Gym.Storage.save(state)}catch(error){Gym.migrationError=error.message;state=Gym.enhanceDemoV2(Gym.Migrations.toV2(Gym.createDemo()));Gym.Storage.save(state)}}Gym.state=state;for(const c of Gym.Integrity.collections)Gym.state[c]=Gym.state[c]||[];Gym.Notifications.generate();Gym.Storage.save(Gym.state)}
  initialize();
  Gym.save=function(){Gym.state.metadata=Gym.state.metadata||{};Gym.state.metadata.lastUpdated=new Date().toISOString();return Gym.Storage.save(Gym.state)};
  Gym.applySettings=function(){document.documentElement.dataset.theme=Gym.state.settings.theme||'light';document.documentElement.classList.toggle('compact',!!Gym.state.settings.compactMode)};
  Gym.render=function(){Gym.app=Gym.Layout.render();Gym.Pages.render(document.body.dataset.page||'dashboard');if(Gym.migrationError)Gym.UI.toast(`V1 migration warning: ${Gym.migrationError}`,'error');if(window.lucide)lucide.createIcons()};
  document.addEventListener('DOMContentLoaded',Gym.render);
})();
