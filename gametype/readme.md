#Gametype Custom Entity - Custom Drupal Entity
Provide simple example for drupal 7.x admin module to do CRUD operations on your own table
##Purpose
Provide an example of developing a custom drupal entity / custom model.
Gametype is simple CRUD operation using Entity with ability to perform search and bulk delete operations

##Dependency
Entity

## Used hooks - Implement hooks
hook_entity_info()
hook_menu()
hook_permission()
hook_theme()

## Used class - Extended core classes
class Gametype extends Entity
class GametypeController extends EntityAPIController
class GametypeUIController extends EntityDefaultUIController

##Note
This is quick demo example from start to end working example for CRUD operations for new developers trying understand drupal framework from development point of view.
This code uses basic security majors offered by drupal core. 
If you wish to use it in production environment then use your own judgement before developing.
Feel free to improve / suggest better way of doing CRUD operations with search and list pager ability.

 