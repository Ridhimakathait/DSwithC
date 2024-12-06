  inorder(root);
    node *res=search(root,7);
    if(res==NULL)
        printf("element not found");
    printf("%d",res->data);