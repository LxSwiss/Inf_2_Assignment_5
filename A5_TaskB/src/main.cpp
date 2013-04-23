//
//  Updated by Rafael Ballester on 09.04.12.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include "avl_tree.hpp"
#include <iostream>


int
main ()
{
  avl_tree tree;

  tree.insert (10);
  tree.insert (4);
  tree.insert (15);
  tree.insert (2);
  tree.insert (7);
   tree.insert (13);
  tree.insert (17);
  tree.insert (1);
  tree.insert (3);
  tree.insert (5);
  tree.insert (9);
  tree.insert (11);


 /* tree.insert (109);
  tree.insert (49);
  tree.insert (159);
  tree.insert (29);
  tree.insert (79);
  tree.insert (139);
  tree.insert (179);
  tree.insert (19);
  tree.insert (39);
  tree.insert (59);
  tree.insert (99);
  tree.insert (191);*/

  std::cout << "Tree is" << (tree.is_balanced ()? "" : " not") << " balanced." << std::endl;	// should be balanced

  std::cout << tree.get_height () << std::endl;	// should be 4
  tree.insert (6);


  std::cout << "Tree is" << (tree.is_balanced ()? "" : " not") << " balanced after insertion of '6'." << std::endl;	// should be still balanced

  return 0;
}

